#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_color.h"

private int jk, jh;
//Pinta o quadrado, parametros sao matriz;tamanho;valor;x;y;lado
void pintaQuadrado(int *, int, int, int, int, int);
//Pinta a martiz, usando o pintaQuadrado. //Parametros:matriz;tamanho;lado;highlight;
void pintaMatriz(int, int);
//Popula a matriz de 1 a 1. Parametros: matriz;tamanho
void populaMatriz(int *, int);
//Embaralha o vetor. Parametros: vetor;tamanho
void embaralhaVetor(int *, int);
//Imprime a matriz no console. Parametros: matriz;linhas;colunas
void imprimeMatriz(int *, int, int);
//Retorna um valor aleatorio.Parametros: vamlor maximo
int randInt(int);
//Troca os valores de posicao. Parametros: primeiro valor, segundo valor
int permuta(int *, int *);

/*****************8FUNCOES************************/

void pintaMatriz(int *matriz, int size, int lado, int highlight) {
	int i, j, k;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			k = i*size + j;
			if (matriz[k] == highlight)
				al_draw_rounded_rectangle(i*lado, j*lado, i*lado + lado, j*lado + lado, 10, 10, al_map_rgb(0, 0, 0), 10);
			else
			pintaQuadrado(matriz, size, matriz[k], lado * i, lado * j, lado);
		}
	}
}

void pintaQuadrado(int *matriz, int size, int value, int x, int y, int lado) {
	int dec = value / 10, uni = value % 10;

	if (dec < size / 2) {
		if (uni > 0 && uni <= 5) {
			al_draw_filled_rectangle(x, y, x + lado, y + lado, cor1);
		}
		else{
			al_draw_filled_rectangle(x, y, x + lado, y + lado, cor2);
		}
	}
	else {
		if (uni > 0 && uni <= 5) {
			al_draw_filled_rectangle(x, y, x + lado, y + lado, cor3);
		}
		else {
			al_draw_filled_rectangle(x, y, x + lado, y + lado, cor4);
		}
	}
	jk += 10;
	jh += 10;
}

void populaMatriz(int *matriz, int size) {
	int i, j, k;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			k = i*size + j;
			matriz[k] = k + 1;
		}
	}
}

void imprimeMatriz(int *mat, int col, int lin) {
	int i, j;
	for (i = 0; i < lin; i++) {
		for (j = 0; j < col; j++) {
			printf(" %d", *(mat + (i*col + j)));
		}
	}
}

int rand_int(int max) {
	int n = max;
	int limit = RAND_MAX - RAND_MAX % n;
	int rnd;

	do {
		rnd = rand();
	} while (rnd >= limit);
	return rnd % n;
}

void embaralhaVetor(int *array, size_t n)
{
	if (n > 1) {
		size_t i;
		for (i = 0; i < n - 1; i++) {
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}

int permuta(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
	return 0;
}
