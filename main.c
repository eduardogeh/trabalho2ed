#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"


int main() {
	
	Heap heap;
	cria_heap(&heap , 20);
	int i;
	for(i=0;i<15;i++){
		insercao(&heap, i);
	}
	impressao_ordem(heap);
	impressao_completa(heap, 0);
	
	for(i=0;i<15;i++){
		remocao(&heap);
		impressao_ordem(heap);
	}
	
	
	return 0;
}
