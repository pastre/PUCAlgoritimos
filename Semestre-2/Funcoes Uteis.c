
//Printa o array,
//Entrada:
  //pt: endereco do array
  //size:  tamanho do array
//Saida: N/A
void printArray(int *pt, int size){
	int i, u;
	for(i = 0; i < size; i++){
		u = pt[i];
		printf("%d\t", u);
	}
}
//Popula o array com entradas do usuario
 //Entrada:
   //array: O array a ser populado(nao sei se precisa, sepa que da pra manipular internamente)
   //size: Tamanho do vetor a ser populado
//Saida: Ponteiro para o vetor com os valores inseridos
int *populaArray(int *array, int size){
	int i, *pt;
	for(i = 0; i < size; i++){
		scanf(" %d", &array[i]);
		fflush(stdin);
	}
	
	return array;
}
//Retorna o ponteiro a um vetor com caracteres diferentes.
//Entrada:
	//*pt: O vetor a ser preenchido
	//size: O tamanho deste vetor
//Saida: O endereco do vetor
int *newRandVet(int *pt, int size){
	int i, j, status;
	srand(time(NULL));
	
	for(i = 0; i < size; i++){
		do{
			pt[i] = rand() % size;
			status = 1;
			for(j = 0; j < i; ++j){
				if(pt[i] == pt[j])
					status = 0;
			}
		}while(status == 0);
	}
	
	return pt;
}

//Faz um quicksort da array.
//Entrada:
  //vet: Vetor a ser organizado
  //ini: O primeiro indice do vetor
  //fim: O ultimo indice do vetor
//Saida: N/A
void quickSort(int *vet, int ini,int fim){
	int ph = ini, i, i2, k, *pt = vet;
	
	for(i = ini + 1; i <= fim; i++){
		i2 = i;
		if(pt[i2] < pt[ph]){
			k = pt[i2];
			while(i2 > ph){
				pt[i2] = pt[i2-1];
				i2--;
			}
			pt[i2] = k;
			ph++;			
		}
	
		if(ph - 1 >= ini)
			quickSort(pt,ini, ph - 1);
		if(ph + 1 <= fim)
			quickSort(pt, ph + 1, fim);
	}
}

//Faz um bubble sort da array. 
//Entrada:
  //vet: endereco do array
  //size: tamanho do array
//Saida: N/A.
void bubSort(int *vet, int size){
	
	int i = size, j, aux;
	for(i = size;i >= 1; i--){
		for(j = 0; j < i; j++){
			if(vet[j] > vet[j+1]){
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
				printf("Trocou %d por %d\n", vet[j], vet[j+1]);
			}
		}
		
	}
	//sleep(2);
	}
	
	//Faz uma pesquisa sequencial no array. 
	//Entrada:
	  //prim: Ponteiro para o primeiro valor do aray(indice 0)
	  //res: O valor que se busca no array
	  //ult: O ultimo valor do array.EX.: Se o array foi declarado com 1000 elementos, deve-se passar o endereco 999 (&vetor[999]).
  //Saida:
    //Posicao da variavel no vetor
	int seqSearch(int *prim, int *res, int *ult){
	int iteracoes;
	
	while(prim != ult){
		if(*prim == *res)
			return iteracoes;			
		//	printf(" %d", *primArray);
		iteracoes++;
		prim++;
	}
	
	return  -1;
}

//Faz uma pesquisa binaria. NOTA: Esta funcao PRECISA da funcao bubSort.
//Entrada:
	//prim: endereco do array onde a variavel sera buscada
	//res: endereco do resultado
	//size: tamanho do vetor a ser varrido
//Saida:
	//mid: Indice da variavel no vetor

int binSearch(int *prim, int *res, int size){
	int mid = size/2, i = 0;
	
		bubSort(prim, size);
	
	while(prim[i]<= prim[size]){
		if(prim[mid] < *res)
			prim[0] = mid + 1;
		else if(prim[mid] == *res){
			return mid; 
			break;
		}
		else
			prim[size] = mid - 1;
		mid = (prim[i] + prim [size]) / 2;
	}
	
	return mid;
}

//Popula uma matriz com valores lidos do teclado
//Entrada:
	//matriz: Endereco da matriz a ser populada
	//lin: numero de linhas da matriz
	//col: numero de colunas da matriz
void populaMatriz(int *matriz, int lin, int col){
	int i,j;	
	puts(" Entre com os valores da matriz\n");
	for (i=0; i<lin; i++)
		for (j=0; j<col; j++){
			printf("Matriz[%d][%d]= ", i,j);
			scanf("%d",matriz+(i*col+j));
		} 
}

//Imprime uma matriz, linha x coluna
//Entrada:
	//mat: Matriz a ser impressa
	//col: numero de colunas da matriz
	//lin: numero de linhas da matriz
void printMat(int *mat, int col, int lin){
	int i, j;
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			printf(" %d", *(mat + (i*col + j)));			
		}
	}
}
//Encontra a diagonal principal de uma matriz
//Entrada:
	//matriz: matriz para se achar a diagonal primaria
	//vetor: ponteiro para o vetor onde serao salvos os valores da diagonal
	//lin: numero de linhs/colunas da matriz
void diagonalPrincipal2x2(int *matriz, int *vetor, int lin){
	int proximoValor, i = 0;
	for(proximoValor = 0; i<lin; proximoValor =proximoValor+ lin+1){
		vetor[i] = *(matriz + proximoValor);
		i++;
	}
}
//Printa na tela os valores da matriz triangular superior
//Entrada:
	//matriz: matriz para se achar os valores
	//lin: numero de linhas ou colunas da matriz
void printaMatrizTriangular(int *matriz, int lin){
	int i, j, k;
	for(i = 0; i < lin; i++)
		for(j = 0; j < lin; j++){
			if(i <= j){
				k = (matriz[j*lin + i]);
				printf(" %d", k);
			}
		}
}
//Encontra a diagonal secundaria da matriz
//Entrada:
	//matriz: matriz para se encontrar a diagonal secundaria
	//vet: vetor onde os valores da diagonal secundaria serao salvos
	//lin: numero de linhas da matriz
//Saida: vetor apontado por *vet com todos os valores da diagonal
void diagonalSecundaria2x2(int *matriz, int *vet, int lin){
	int proximoValor, i = 0;
	for(proximoValor = lin; i < lin; proximoValor += lin - 1, i++){
		vet[i] = *(matriz + proximoValor);
	}
	
}


