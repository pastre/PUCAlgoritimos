#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_color.h"
#include "C:\Users\Bruno Pastre\Desktop\FuncoesUteisMatrizes.c"

#define SIZE 10
#define LADO_QUADRADO 50
#define PRETO -1
#define WDT 800
#define HGT 600
#define SLEEP 500

int n;

int pegaPecaFora(int *matriz, int size) {
	int i, j, k;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++) {
			k = i*size + j;
			if (matriz[k] != k && matriz[k] != PRETO)
				return k;
		}
	return 1;
}
int pegaPreta(int *matriz, int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			if (matriz[i*size + j] == PRETO)
				return i*size + j;
	}
	return -1;
}
//INDICE É O INDICE DE SAIDA, DESTINO E O INDICE DE DESTINO
void sobePeca(int *matriz, int size) {
	int peca = pegaPreta(matriz, size);
	permuta(&matriz[peca], &matriz[peca - size]);
	imprimeMatriz(matriz, size, size);
	pintaMatriz(matriz, size, LADO_QUADRADO, PRETO, pegaPecaFora(matriz, size));
	al_flip_display();
	Sleep(SLEEP);
}
void descePeca(int *matriz, int size) {
	int peca = pegaPreta(matriz, size);
	permuta(&matriz[peca], &matriz[peca + size]);
	imprimeMatriz(matriz, size, size);
	pintaMatriz(matriz, size, LADO_QUADRADO, PRETO, pegaPecaFora(matriz, size));
	al_flip_display();
	Sleep(SLEEP);
}
void trasPeca(int *matriz, int size) {
	int peca = pegaPreta(matriz, size);
	permuta(&matriz[peca], &matriz[peca - 1]);
	imprimeMatriz(matriz, size, size);
	pintaMatriz(matriz, size, LADO_QUADRADO, PRETO, pegaPecaFora(matriz, size));
	al_flip_display();
	Sleep(SLEEP);
}
void avancaPeca(int *matriz, int size) {
	int peca = pegaPreta(matriz, size);
	permuta(&matriz[peca], &matriz[peca + 1]);
	imprimeMatriz(matriz, size, size);
	pintaMatriz(matriz, size, LADO_QUADRADO, PRETO, pegaPecaFora(matriz, size));
	al_flip_display();
	Sleep(SLEEP);
}
int arrumaPreta(int *matriz, int size, int dest) {
	int linhaSaida = pegaPreta(matriz, size) / 10, linhaDestino = pegaPecaFora(matriz, size) / 10;
	int colSaida = pegaPreta(matriz, size) % 10, colDestino = (pegaPecaFora(matriz, size) % 10);
	//int linhaDestino = dest / 10, colDestino = dest % 10;
	Sleep(SLEEP);
	//	printf("\nA peca fora na matriz e %d e tem valor %d\n", pegaPecaFora(matriz, size), matriz[pegaPecaFora(matriz, size)]);
	if (linhaSaida != linhaDestino) {
		if (linhaSaida > linhaDestino) {
			sobePeca(matriz, size);
			return arrumaPreta(matriz, size, dest);
		}
		else if (linhaSaida < linhaDestino) {
			descePeca(matriz, size);
			return arrumaPreta(matriz, size, dest);
		}
	}
	else if (colSaida != colDestino) {
		if (colSaida == colDestino - 1)
			return 1;
		if (colSaida > colDestino) {
			trasPeca(matriz, size);
			return arrumaPreta(matriz, size, dest);
		}
		else if (colSaida < colDestino) {
			avancaPeca(matriz, size);
			return arrumaPreta(matriz, size, dest);
		}
	}
	/*
	if(linhaSaida != linhaDestino)
	while (linhaSaida != linhaDestino) {
	Sleep(SLEEP);
	if (linhaSaida > linhaDestino) {
	sobePeca(matriz, size, pegaPreta(matriz, size));
	//return arrumaPreta(matriz, size, dest);
	}
	else if (linhaSaida < linhaDestino) {
	descePeca(matriz, size, pegaPreta(matriz, size));
	//return arrumaPreta(matriz, size, dest);
	}
	}

	while (colSaida != colDestino) {
	Sleep(SLEEP);
	if (colSaida == colDestino)
	break;
	else  if (colSaida > colDestino) {
	trasPeca(matriz, size, pegaPreta(matriz, size));;
	//	return arrumaPreta(matriz, size, dest);
	}
	else if (colSaida < colDestino) {
	avancaPeca(matriz, size, pegaPreta(matriz, size));
	//return arrumaPreta(matriz, size, dest);
	}
	}*/
	return -1;
}
int posNaMatriz(int *matriz, int size, int valor) {
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
int acertaLinhaPeca(int *matriz, int size, int peca, int *offset) {
	int linDaPeca = peca / size;
	int linCerta = matriz[peca] / size;
	if (linDaPeca == linCerta)
		return 1;
	else if (linDaPeca < linCerta) {
		descePeca(matriz, size);
		avancaPeca(matriz, size);
		sobePeca(matriz, size);
		trasPeca(matriz, size);
		descePeca(matriz, size);
		*offset += size;
		return acertaLinhaPeca(matriz, size, peca += size, offset);
	}
	else if (linDaPeca > linCerta) {
		printf("\nMENOR\n");
		sobePeca(matriz, size);
		avancaPeca(matriz, size);
		descePeca(matriz, size);
		trasPeca(matriz, size);
		sobePeca(matriz, size);
		*offset -= size;
		return acertaLinhaPeca(matriz, size, peca -= size, offset);
	}
	return 1;
}
int acertaColunaPeca(int *matriz, int size, int peca) {
	int colDaPeca = peca % size;
	int colCerta = matriz[peca] % size;
	printf("\nCOL:%d\tCERTA:%d\n", colDaPeca, colCerta);
	printf("\n\n\n\n O VALOR DA PECA E %d\n\n\n\n", peca);
	if (colDaPeca == colCerta)
		return 1;
	else if (colDaPeca < colCerta) {
		sobePeca(matriz, size);
		avancaPeca(matriz, size);
		avancaPeca(matriz, size);
		descePeca(matriz, size);
		trasPeca(matriz, size);
		return acertaColunaPeca(matriz, size, peca++);
	}
	else if (colDaPeca > colCerta) {
		avancaPeca(matriz, size);
		sobePeca(matriz, size);
		trasPeca(matriz, size);
		trasPeca(matriz, size);
		descePeca(matriz, size);
		return acertaColunaPeca(matriz, size, peca--);
	}
	return 1;
}
int organiza(int *matriz, int size) {
	///repensar esta logica!!!!!!!!!!!!!!
	int i, j, k, o = 0, *os = &o;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			k = i*size + j;
			if (matriz[k] != k && matriz[k] != PRETO) {
				//	arrumaPreta(matriz, size, k);
				arrumaPreta(matriz, size, k);
				printf("VOU ARRUMAR O VALOR %d, NA MATRIZ %d", k + 1, matriz[k + 1]);
				acertaLinhaPeca(matriz, size, k + 1, os);
				printf("\n\n\nA LINHA TA CERTA\n");
				k += *os;
				acertaColunaPeca(matriz, size, k + 1);
				printf("\n\n\n\nA COLUNA TA CERTA\n\n\n");
				*os = 0;
			}
		}
	}

	//acertaLinhaPeca(matriz, size, pecaFora);
	return 1;
}
int main() {
	int matriz[SIZE][SIZE];
	int *ptMat = &matriz[0][0];

	if (!al_init())
		return -1;
	if (!al_init_primitives_addon())
		return -1;

	ALLEGRO_DISPLAY *display = al_create_display(WDT, HGT);

	populaMatriz(ptMat, SIZE);
	pintaMatriz(ptMat, SIZE, LADO_QUADRADO, PRETO, NULL);
	al_flip_display();
	embaralhaVetor(ptMat, SIZE * SIZE);
	matriz[3][5] = PRETO;
	pintaMatriz(ptMat, SIZE, LADO_QUADRADO, PRETO, pegaPecaFora(ptMat, SIZE));
	al_flip_display();

	organiza(ptMat, SIZE);

	system("pause");
	return 0;
}
