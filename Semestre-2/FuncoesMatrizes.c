#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_color.h"
#include "allegro5\allegro_font.h"

#define cor1  al_map_rgb(0, 255, 0)
#define cor2  al_map_rgb(0, 0, 255)
#define cor3  al_map_rgb(255, 0, 0)
#define cor4  al_map_rgb(255, 255, 0)

int jk, jh;
//Pinta o quadrado, parametros sao matriz;tamanho;valor;x;y;lado
void pintaQuadrado(int *, int, int, int, int, int, int);
//Pinta a martiz, usando o pintaQuadrado. //Parametros:matriz;tamanho;lado;highlight;
void pintaMatriz(int *, int, int, int, int);
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

void pintaMatriz(int *matriz, int size, int lado, int highlight, int obj) {
	int i, j, k;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			k = i*size + j;
			if (matriz[k] == highlight) {
				//al_draw_filled_rectangle(i*lado, j*lado, i*lado + lado, j*lado + lado, al_map_rgb(0, 0, 0));
				al_draw_filled_rectangle(j*lado, i*lado, j*lado + lado, i*lado + lado, al_map_rgb(0, 0, 0));
			}
			else if(matriz[k] >= 0)
				//pintaQuadrado(matriz, size, matriz[k], lado * i, lado * j, lado, obj);
				pintaQuadrado(matriz, size, matriz[k], lado * j, lado * i, lado, obj);
			else
				al_draw_filled_rectangle(i*lado, j*lado, i*lado + lado, j*lado + lado, al_map_rgb(43, 255, 0));
		}
	}
}

void pintaQuadrado(int *matriz, int size, int value, int x, int y, int lado, int obj) {
	int dec = value / 10, uni = value % 10;
	
	if (dec < size / 2) {
		//if (uni > 0 && uni <= 5) {
		if(uni < size / 2){
			al_draw_filled_rectangle(x, y, x + lado, y + lado, cor1);
			if (value == obj)
				al_draw_rectangle(x, y, x + lado, y + lado, al_map_rgb(255, 255, 255), lado / 10);
			else
				al_draw_rectangle(x, y, x + lado, y + lado, al_map_rgb(0, 0, 0), lado / 10);
		}
		else {
			al_draw_filled_rectangle(x, y, x + lado, y + lado, cor2);
			if (value == obj)
				al_draw_rectangle(x, y, x + lado, y + lado, al_map_rgb(255, 255, 255), lado / 8);
			else
			al_draw_rectangle(x, y, x + lado, y + lado, al_map_rgb(0, 0, 0), lado / 10);
		}
	}
	else {
	//	if (uni > 0 && uni <= 5) {
		if(uni < size / 2){
			al_draw_filled_rectangle(x, y, x + lado, y + lado, cor3);
			if (value == obj)
				al_draw_rectangle(x, y, x + lado, y + lado, al_map_rgb(255, 255, 255), lado / 10);
			else
			al_draw_rectangle(x, y, x + lado, y + lado, al_map_rgb(0, 0, 0), lado / 10);
		}
		else {
			al_draw_filled_rectangle(x, y, x + lado, y + lado, cor4);
			if (value == obj)
				al_draw_rectangle(x, y, x + lado, y + lado, al_map_rgb(255, 255, 255), lado / 8);
			else
			al_draw_rectangle(x, y, x + lado, y + lado, al_map_rgb(0, 0, 0), lado / 10);
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
			matriz[k] = k;
		}
	}
}

void imprimeMatriz(int *mat, int col, int lin) {
	int i, j;
	printf("\n");
	for (i = 0; i < lin; i++) {
		for (j = 0; j < col; j++) {
			printf(" %d", *(mat + (i*col + j)));
		}
		printf("\n");
	}
	printf("-------------------------------------------------------------");
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

void embaralhaVetor(int *array, int n)
{
	if (n > 1) {
		int i, j;
		for (i = 0; i < n - 1; i++) {
			j = i + rand() / (RAND_MAX / (n - i) + 1);
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

