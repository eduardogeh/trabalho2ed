
struct heap_binario{
	int tam;
	int* vet;
	int indice_atual;
};
typedef struct heap_binario Heap;

void cria_heap(Heap* H, int tamanho);

void balanceamento(Heap* H, int indice);

void insercao(Heap* H, int num);

void balanceamento_remocao(Heap *H, int indice);

void remocao(Heap *H);

void impressao_ordem(Heap H);
void impressao_de_filhos(Heap H, int indice);

void impressao_completa(Heap H, int indice);
