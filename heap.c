#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"
void cria_heap(Heap* H, int tamanho){
	
	H->tam= tamanho;
	H->vet = malloc(tamanho*sizeof(int));
	
	H->indice_atual = 0;
	printf("\nO heap de tamanho %d foi criado com sucesso", tamanho);
}

void balanceamento(Heap* H, int indice){
	if(indice == 0)
		return;
	int par_impar = indice % 2;
	//se der 0 é par , se der 1 é impar
	int indice_pai;
	
	if(par_impar == 1)
		indice_pai= (indice-1) / 2;
	else
		indice_pai= (indice-2) / 2;
	
	if(H->vet[indice] > H->vet[indice_pai]){
		
		int aux = H->vet[indice];
		H->vet[indice]= H->vet[indice_pai];
		H->vet[indice_pai]= aux;
		//chama de novo para balancear
		balanceamento(H, indice_pai);
	}
}

void insercao(Heap* H, int num){
	
	if(H->indice_atual + 1 > H->tam){
		printf("Estouro de tamanho");
		return;
	}
	
	printf("\ninserindo o numero %d no Heap", num);
	
	H->vet[ H->indice_atual ] = num;
	
	balanceamento(H, H->indice_atual);
	
	H->indice_atual++;
}

void balanceamento_remocao(Heap *H, int indice){
	
	if(indice > H->indice_atual)
		return;
		
	bool dir = false, esq = false;
	int maior;
	
	//existe esquerda?
	if(indice*2+1<= H->indice_atual)
		esq= true;
		
	//existe direita?
	if(indice*2+2 <= H->indice_atual)
		dir=true;
	
	if(dir && esq){
		int aux= H->vet[indice];
		
		if(H->vet[indice*2+2] > H->vet[indice*2+1]){
			//direita é maior
			if(H->vet[indice*2+2] > H->vet[indice]){
				 H->vet[indice]= H->vet[indice*2+2];
				 H->vet[indice*2+2]= aux;
				 balanceamento_remocao(H, indice*2+2);
			}
			
		}else{
			//esquerda é maior
			if(H->vet[indice*2+1]> H->vet[indice]){
				H->vet[indice]= H->vet[indice*2+1];
				 H->vet[indice*2+1]= aux;
				 balanceamento_remocao(H, indice*2+1);
			}
			
		}
	}else if(dir || esq){
		int aux= H->vet[indice];
		if(dir){
			if(H->vet[indice*2+2]> H->vet[indice]){
				 H->vet[indice]= H->vet[indice*2+2];
				 H->vet[indice*2+2]= aux;
				 balanceamento_remocao(H, indice*2+2);
			}
		}else{
			if(H->vet[indice*2+1]> H->vet[indice]){
				H->vet[indice]= H->vet[indice*2+1];
				 H->vet[indice*2+1]= aux;
				 balanceamento_remocao(H, indice*2+1);
			}
		}
	}
	
	//verificar a esquerda e direita e ver qual o maior
}


void remocao(Heap *H){
	
	if(H->indice_atual==0){
		printf("\Esta vazio, nao tem como retirar");
		return;
	}
	
	H->vet[0]= H->vet[ H->indice_atual-1 ];
	H->indice_atual--;
	balanceamento_remocao(H, 0);
	
}

void impressao_ordem(Heap H){
	int i;
	
	printf("\nTermos:\n");
	
	for(i=0; i < H.indice_atual; i++){
		printf("%d ",H.vet[i]);
	}
	printf("\n");
}

void impressao_de_filhos(Heap H, int indice){
	if(indice < H.indice_atual){
		printf("%d ", H.vet[indice]);
	}else{
		printf("nao tem");
	}
}

void impressao_completa(Heap H, int indice){
	int i;
	if(indice >= H.indice_atual){
		return;
	}
	printf("\ntermo: %d", H.vet[indice]);
	printf("\nfilho da direita: ");
	
	impressao_de_filhos(H, indice*2+2);
	
	printf("\nfilho da esquerda: ");
	impressao_de_filhos(H, indice*2+1);
	
	impressao_completa(H, indice*2+1);
	impressao_completa(H, indice*2+2);
	
}

