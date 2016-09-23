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
#define SLEEP 10

int limite = 8;
int pegaPreta(int *matriz, int size) {
	int i, j, k;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			k = j*size + i;
			if (matriz[k] < 0)
				return k;
		}
	}

	return 110;
}
//Retorta a POSICAO dovalor fora do lugar
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
int pegaQuadrante(int size, int valor) {
	int linha = valor / size, coluna = valor% size;
	if (linha < size / 2) {
		if (coluna < size / 2)
			return 2;
		else
			return 1;
	}
	else
		if (coluna < size / 2)
			return 3;
		else
			return 4;

	return -1;
}
int saoDaMesmaCor(int *matriz, int size, int valorA, int valorB) {
	if (pegaQuadrante(size, valorA) == pegaQuadrante(size, valorB))
		return 1;
	return 0;
}
int valorDaProxPecaFora(int *matriz, int size) {
	int i, j, k, l;
	//for (l = size - 1; l >= 0; l--)
	for (i = size - 1; i > size / 2; i--) {
		for (j = size - 1; j >= 0; j--) {
			k = i*size + j;
			printf("\nLoopei %d\n", k);
			if (matriz[k] != k && matriz[k] != PRETO /*&& /**saoDaMesmaCor(matriz, size, matriz[k], k != 1)*/)
				return k;
		}
	}

	for (i = size / 2; i >= 0; i--) {
		for (j = size / 2; j >= 0; j++){
			k = j*size + i;
			printf("\nLoopei %d\n", k);
			if (matriz[k] != k && matriz[k] != PRETO /*&& /**saoDaMesmaCor(matriz, size, matriz[k], k != 1)*/)
				return k;

}
	}
	return -1;
}
int arrumaPreta(int *matriz, int size, int valor) {
	int posDoValor = posValor(matriz, size, valor), posDaPreta = pegaPreta(matriz, size);

	 
		if (matriz[posDoValor + 1] == PRETO) {
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
		printf("A preta ta alinhada com a peca de valor %d", valor);
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
int arrumaPeca(int *matriz, int size) {
	int posDaPeca = pegaPreta(matriz, size) + 1;
	int posCertaDaPeca = valorDaProxPecaFora(matriz, size);
	if (posCertaDaPeca % 10 == 0) {

		if (posDaPeca == posCertaDaPeca)
			return 1;
		else if (posDaPeca + 1 == posCertaDaPeca) {
			///DE A VOLTA
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			return 1;
		}
		else if (posDaPeca - 1 == posCertaDaPeca) {
			///DE A VOLTA
			avancaPeca(matriz, size);
			return 1;
		}
		else if (posDaPeca + size == posCertaDaPeca) {
			///MOVA PARA BAIXO,
			descePeca(matriz, size);
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			return 1;
		}
		else if (posDaPeca - size == posCertaDaPeca) {
			///mova para cima
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			return 1;
		}

		
		else if ((posDaPeca / 10)+1 > posCertaDaPeca / 10) {
			///SUBA A PECA
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			sobePeca(matriz, size);
			return arrumaPeca(matriz, size);
		}
		else if ((posDaPeca / 10)+1 < posCertaDaPeca / 10) {
			///DESCA A PECA
			descePeca(matriz, size);
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			trasPeca(matriz, size);
			descePeca(matriz, size);
			return arrumaPeca(matriz, size);
		}
		else if (posDaPeca % 10 > posCertaDaPeca % 10) {
			///VOLTE A PECA
			if (posDaPeca / 10 == 0) {
				avancaPeca(matriz, size);
				descePeca(matriz, size);
				trasPeca(matriz, size);
				trasPeca(matriz, size);
				sobePeca(matriz, size);
				return arrumaPeca(matriz, size);
			}
			else {
				avancaPeca(matriz, size);
				sobePeca(matriz, size);
				trasPeca(matriz, size);
				trasPeca(matriz, size);
				descePeca(matriz, size);
				return arrumaPeca(matriz, size);
			}
		}
		else if (posDaPeca % 10 < posCertaDaPeca % 10) {
			///AVANCE A PECA
			if (posDaPeca / 10 == 0) {
				descePeca(matriz, size);
				avancaPeca(matriz, size);
				avancaPeca(matriz, size);
				sobePeca(matriz, size);
				trasPeca(matriz, size);
				return arrumaPeca(matriz, size);
			}
			else {
				sobePeca(matriz, size);
				avancaPeca(matriz, size);
				avancaPeca(matriz, size);
				descePeca(matriz, size);
				trasPeca(matriz, size);
				return arrumaPeca(matriz, size);
			}
		}

	}
	else {
		if (posDaPeca == posCertaDaPeca)
			return 1;
		else if (posDaPeca + 1 == posCertaDaPeca) {
			///DE A VOLTA
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			return 1;
		}
		else if (posDaPeca - 1 == posCertaDaPeca) {
			///DE A VOLTA
			avancaPeca(matriz, size);
			return 1;
		}
		else if (posDaPeca + size == posCertaDaPeca) {
			///MOVA PARA BAIXO
			descePeca(matriz, size);
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			return 1;
		}
		else if (posDaPeca - size == posCertaDaPeca) {
			///mova para cima
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			return 1;
		}

		else if (posDaPeca % 10 > posCertaDaPeca % 10) {
			///VOLTE A PECA
			if (posDaPeca / 10 == 0) {
				avancaPeca(matriz, size);
				descePeca(matriz, size);
				trasPeca(matriz, size);
				trasPeca(matriz, size);
				sobePeca(matriz, size);
				return arrumaPeca(matriz, size);
			}
			else {
				avancaPeca(matriz, size);
				sobePeca(matriz, size);
				trasPeca(matriz, size);
				trasPeca(matriz, size);
				descePeca(matriz, size);
				return arrumaPeca(matriz, size);
			}
		}
		else if (posDaPeca % 10 < posCertaDaPeca % 10) {
			///AVANCE A PECA
			if (posDaPeca / 10 == 0) {
				descePeca(matriz, size);
				avancaPeca(matriz, size);
				avancaPeca(matriz, size);
				sobePeca(matriz, size);
				trasPeca(matriz, size);
				return arrumaPeca(matriz, size);
			}
			else {
				sobePeca(matriz, size);
				avancaPeca(matriz, size);
				avancaPeca(matriz, size);
				descePeca(matriz, size);
				trasPeca(matriz, size);
				return arrumaPeca(matriz, size);
			}
		}

		else if (posDaPeca / 10 > posCertaDaPeca / 10) {
			///SUBA A PECA
			sobePeca(matriz, size);
			avancaPeca(matriz, size);
			descePeca(matriz, size);
			trasPeca(matriz, size);
			sobePeca(matriz, size);
			return arrumaPeca(matriz, size);
		}
		else if (posDaPeca / 10 < posCertaDaPeca / 10) {
			///DESCA A PECA
			descePeca(matriz, size);
			avancaPeca(matriz, size);
			sobePeca(matriz, size);
			trasPeca(matriz, size);
			descePeca(matriz, size);
			return arrumaPeca(matriz, size);
		}
	}
	return -1;
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
	embaralhaVetor(ptMat, SIZE * SIZE);
	matriz[0][0] = PRETO;
	pintaMatriz(ptMat, SIZE, LADO_QUADRADO, PRETO, NULL);
	al_flip_display();
	imprimeMatriz(ptMat, SIZE, SIZE);

	int valorFora;
	//do{
	while (1) {
		valorFora = valorDaProxPecaFora(ptMat, SIZE);
		printf("\n\n%d\n\n", valorFora);
		arrumaPreta(ptMat, SIZE, valorFora);
		arrumaPeca(ptMat, SIZE);
		resetaPreta(ptMat, SIZE);
	}
	//} while (valorFora != -1);
//	while (valorFora != -1) {
		//Arruma a peca de valor valorFora
	//	arrumaPeca(matriz, size, valorFora);
		//Sleep(SLEEP);
		//valorFora = valorDaProxPecaFora(matriz, size);
	//}

	system("pause");
	return 0;
}
