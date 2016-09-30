#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_color.h"
#include "C:\Users\Bruno Pastre\Desktop\FuncoesUteisMatrizes.c"

#define SIZE 10
#define LADO_QUADRADO 50
#define PRETO -10
#define WDT 800
#define HGT 600
#define SLEEP 0

int resetaPreta(int *, int);

int pegaPreta(int *matriz, int size) {
	int i, j, k;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			k = j*size + i;
			if (matriz[k] == PRETO) {
				return k;
			}
		}
	}

	return 110;
}
int posValor(int *matriz, int size, int valor) {
	int i, j, k;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			k = i*size + j;
			if (matriz[k] == valor)
				return k;
		}
	}
	return -1;
}
void sobePeca(int *matriz, int size) {
	int peca = pegaPreta(matriz, size);
	permuta(&matriz[peca], &matriz[peca - size]);
	imprimeMatriz(matriz, size, size);
	pintaMatriz(matriz, size, LADO_QUADRADO, PRETO, NULL);
	al_flip_display();
	Sleep(SLEEP);
}
void descePeca(int *matriz, int size) {
	int peca = pegaPreta(matriz, size);
	permuta(&matriz[peca], &matriz[peca + size]);
	imprimeMatriz(matriz, size, size);
	pintaMatriz(matriz, size, LADO_QUADRADO, PRETO, NULL);
	al_flip_display();
	Sleep(SLEEP);
}
void trasPeca(int *matriz, int size) {
	int peca = pegaPreta(matriz, size);
	permuta(&matriz[peca], &matriz[peca - 1]);
	imprimeMatriz(matriz, size, size);
	pintaMatriz(matriz, size, LADO_QUADRADO, PRETO, NULL);
	al_flip_display();
	Sleep(SLEEP);
}
void avancaPeca(int *matriz, int size) {
	int peca = pegaPreta(matriz, size);
	permuta(&matriz[peca], &matriz[peca + 1]);
	imprimeMatriz(matriz, size, size);
	pintaMatriz(matriz, size, LADO_QUADRADO, PRETO, NULL);
	al_flip_display();
	Sleep(SLEEP);
}
int valorDaProxPecaFora(int *matriz, int size) {
	int i, j, k;
	for (i = size - 1; i >= 3; i--) {
		for (j = size - 1; j >= 0; j--) {
			k = i*size + j;
			if (matriz[k] != k && matriz[k] != PRETO) {
				printf("\nVou arrumar a %d \n", k);
				return k;
			}
		}
	}	
	for (i = 3; i >= 0; i--) {
		for (j = size - 1; j >= 0; j--) {
		k = i*size + j;
			if (matriz[k] != PRETO && posValor(matriz, size, k) % size < size / 2 && k % size > size / 2) {
				return k;
			}
		}
	}
	resetaPreta(matriz, size);
	for (i = size - 1; i >= 0; i--) {
		for (j = size - 1; j >= 0; j--) {
			k = i*size + j;
			if (matriz[k] != k && matriz[k] != PRETO) {
				return k;
			}
		}
	}
		return -30000;
}
int arrumaPreta(int *matriz, int size, int valor) {
	int posDoValor = posValor(matriz, size, valor), posDaPreta = pegaPreta(matriz, size);
	if (posDoValor / size == 0) {
		if (matriz[posDoValor + 1] == PRETO) {
			trasPeca(matriz, size);
			return 1;
		}
		else if (matriz[posDoValor + size] == PRETO) {
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			trasPeca(matriz, size);
			return 1;
		}
		else if (matriz[posDoValor - size] == PRETO) {
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			return 1;
		}
		else if (posDoValor / size > posDaPreta / 10) {
			descePeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
		else if (posDoValor / size < posDaPreta / 10) {
			sobePeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
		else if (posDoValor % size > posDaPreta % size) {
			avancaPeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
		else if (posDoValor % size < posDaPreta % size) {
			trasPeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
		printf("A preta ta alinhada com a peca de valor %d", valor);
		return -1;
	}
	if (posDoValor % size == 0) {
		if (matriz[posDoValor + 1] == PRETO) {
			trasPeca(matriz, size);
			return 1;
		}
		else if (matriz[posDoValor + size] == PRETO) {
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			trasPeca(matriz, size);
			return 1;
		}
		else if (matriz[posDoValor - size] == PRETO) {
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			return 1;
		}
		else if (posDoValor / 10 > posDaPreta / 10) {
			descePeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
		else if (posDoValor / 10 < posDaPreta / 10) {
			sobePeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
		else if (posDoValor % size > posDaPreta % size) {
			avancaPeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
		else if (posDoValor % size < posDaPreta % size) {
			trasPeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
		printf("A preta ta alinhada com a peca de valor %d", valor);
		return -1;
	}
	else if (matriz[posDoValor + 1] == PRETO) {
		if (posDoValor / 10 == 0) {
			descePeca(matriz, size);
			trasPeca(matriz, size);
			trasPeca(matriz, size);
			sobePeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
		else {
			sobePeca(matriz, size);
			trasPeca(matriz, size);
			trasPeca(matriz, size);
			descePeca(matriz, size);
			return arrumaPreta(matriz, size, valor);
		}
	}
	else if (matriz[posDoValor - 1] == PRETO) {
		return 1;
	}
	else if (matriz[posDoValor + size] == PRETO) {
		trasPeca(matriz, size);
		sobePeca(matriz, size);
		return arrumaPreta(matriz, size, valor);
	}
	else if (matriz[posDoValor - size] == PRETO) {
		trasPeca(matriz, size);
		descePeca(matriz, size);
		return arrumaPreta(matriz, size, valor);
	}
	else if (posDoValor / 10 > posDaPreta / 10) {
		descePeca(matriz, size);
		return arrumaPreta(matriz, size, valor);
	}
	else if (posDoValor / 10 < posDaPreta / 10) {
		sobePeca(matriz, size);
		return arrumaPreta(matriz, size, valor);
	}
	else if (posDoValor % size > posDaPreta % size) {
		avancaPeca(matriz, size);
		return arrumaPreta(matriz, size, valor);
	}
	else if (posDoValor % size < posDaPreta % size) {
		trasPeca(matriz, size);
		return arrumaPreta(matriz, size, valor);
	}
	return -1;

}
int resetaPreta(int *ptMat, int size) {
	while (pegaPreta(ptMat, SIZE) / 10 != 0) {
		sobePeca(ptMat, SIZE);
	}
	while (pegaPreta(ptMat, SIZE) % 10 != 0) {
		trasPeca(ptMat, SIZE);
	}
	return 0;
}
int arrumaPeca(int *matriz, int size, int peca) {
	int posDaPeca = posValor(matriz, size, peca);
	int posCertaDaPeca = peca;

	if (posCertaDaPeca % size == 0) {
		if (posDaPeca == posCertaDaPeca)
			return 1;
		else if (posDaPeca + 1 == posCertaDaPeca) {
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			return 1;
		}
		else if (posDaPeca - 1 == posCertaDaPeca) {
			avancaPeca(matriz, size);
			return 1;
		}
		else if (posDaPeca + size == posCertaDaPeca) {
			descePeca(matriz, size);
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			return 1;
		}
		else if (posDaPeca - size == posCertaDaPeca) {
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			return 1;
		}


		else if ((posDaPeca / 10) + 1 > posCertaDaPeca / 10) {
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			sobePeca(matriz, size);
			return arrumaPeca(matriz, size, peca);
		}
		else if ((posDaPeca / 10) + 1 < posCertaDaPeca / 10) {
			descePeca(matriz, size);
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			trasPeca(matriz, size);
			descePeca(matriz, size);
			return arrumaPeca(matriz, size, peca);
		}
		else if (posDaPeca % 10 > posCertaDaPeca % 10) {
			if (posDaPeca / 10 == 0) {
				avancaPeca(matriz, size);
				descePeca(matriz, size);
				trasPeca(matriz, size);
				trasPeca(matriz, size);
				sobePeca(matriz, size);
				return arrumaPeca(matriz, size, peca);
			}
			else {
				avancaPeca(matriz, size);
				sobePeca(matriz, size);
				trasPeca(matriz, size);
				trasPeca(matriz, size);
				descePeca(matriz, size);
				return arrumaPeca(matriz, size, peca);
			}
		}
		else if (posDaPeca % 10 < posCertaDaPeca % 10) {
			if (posDaPeca / 10 == 0) {
				descePeca(matriz, size);
				avancaPeca(matriz, size);
				avancaPeca(matriz, size);
				sobePeca(matriz, size);
				trasPeca(matriz, size);
				return arrumaPeca(matriz, size, peca);
			}
			else {
				sobePeca(matriz, size);
				avancaPeca(matriz, size);
				avancaPeca(matriz, size);
				descePeca(matriz, size);
				trasPeca(matriz, size);
				return arrumaPeca(matriz, size, peca);
			}
		}

	}
	else {
		if (posDaPeca == posCertaDaPeca)
			return 1;
		else if (posDaPeca + 1 == posCertaDaPeca) {
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			return 1;
		}
		else if (posDaPeca - 1 == posCertaDaPeca) {
			avancaPeca(matriz, size);
			return 1;
		}
		else if (posDaPeca + size == posCertaDaPeca) {
			descePeca(matriz, size);
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			return 1;
		}
		else if (posDaPeca - size == posCertaDaPeca) {
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			return 1;
		}

		else if (posDaPeca % 10 > posCertaDaPeca % 10) {
			if (posDaPeca / 10 == 0) {
				avancaPeca(matriz, size);
				descePeca(matriz, size);
				trasPeca(matriz, size);
				trasPeca(matriz, size);
				sobePeca(matriz, size);
				return arrumaPeca(matriz, size, peca);
			}
			else {
				avancaPeca(matriz, size);
				sobePeca(matriz, size);
				trasPeca(matriz, size);
				trasPeca(matriz, size);
				descePeca(matriz, size);
				return arrumaPeca(matriz, size, peca);
			}
		}
		else if (posDaPeca % 10 < posCertaDaPeca % 10) {
			if (posDaPeca / 10 == 0) {
				descePeca(matriz, size);
				avancaPeca(matriz, size);
				avancaPeca(matriz, size);
				sobePeca(matriz, size);
				trasPeca(matriz, size);
				return arrumaPeca(matriz, size, peca);
			}
			else {
				sobePeca(matriz, size);
				avancaPeca(matriz, size);
				avancaPeca(matriz, size);
				descePeca(matriz, size);
				trasPeca(matriz, size);
				return arrumaPeca(matriz, size, peca);
			}
		}

		else if (posDaPeca / 10 > posCertaDaPeca / 10) {
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			sobePeca(matriz, size);
			return arrumaPeca(matriz, size, peca);
		}
		else if (posDaPeca / 10 < posCertaDaPeca / 10) {
			descePeca(matriz, size);
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			trasPeca(matriz, size);
			descePeca(matriz, size);
			return arrumaPeca(matriz, size, peca);
		}
	}
	return -1;
}
int arrumaTudo(int *matriz, int size) {
	int valorFora = valorDaProxPecaFora(matriz, size);
	printf("\n*****\n VALOR: %d\n****************\n", valorFora);
	if (valorFora > 0) {
		if (valorFora == 18 || valorFora == 17 || valorFora == 12 || valorFora == 16 ) {
			resetaPreta(matriz, size);
		}
		arrumaPreta(matriz, size, valorFora);
		arrumaPeca(matriz, size, valorFora);
		return arrumaTudo(matriz, size);
	}
	else return 1;
}
int main() {
	if (!al_init())
		return -1;
	if (!al_init_primitives_addon())
		return -1;

	int matriz[SIZE][SIZE];
	int *ptMat = &matriz[0][0];
	ALLEGRO_DISPLAY *display = al_create_display(WDT, HGT);

	populaMatriz(ptMat, SIZE);
	pintaMatriz(ptMat, SIZE, LADO_QUADRADO, PRETO, NULL);
	al_flip_display();
	imprimeMatriz(ptMat, SIZE, SIZE);
	Sleep(1000);
	matriz[0][0] = PRETO;
	embaralhaVetor(ptMat, SIZE * SIZE);
	pintaMatriz(ptMat, SIZE, LADO_QUADRADO, PRETO, NULL);
	al_flip_display();
	imprimeMatriz(ptMat, SIZE, SIZE);

	arrumaTudo(ptMat, SIZE);
	
	system("pause");
	return 0;
}
