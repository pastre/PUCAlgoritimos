
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


