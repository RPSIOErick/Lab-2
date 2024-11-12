#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void** fila;
    int frente;
    int final;
    int capacidade;
    int tamanho;
} FilaCircular;

FilaCircular* criaFila(int capacidade) {
    FilaCircular* fila = (FilaCircular*)malloc(sizeof(FilaCircular));
    fila->capacidade = capacidade;
    fila->fila = (void**)malloc(capacidade * sizeof(void*));
    fila->frente = 0;
    fila->final = -1;
    fila->tamanho = 0;
    return fila;
}

void enfileira(FilaCircular* fila, void* obj) {
    if (fila->tamanho == fila->capacidade) {
        printf("Fila cheia!\n");
        return;
    }
    fila->final = (fila->final + 1) % fila->capacidade;
    fila->fila[fila->final] = obj;
    fila->tamanho++;
}

void* desenfileira(FilaCircular* fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia!\n");
        return NULL;
    }
    int indice = fila->frente;
    fila->frente = (fila->frente + 1) % fila->capacidade;
    fila->tamanho--;
    return fila->fila[indice];
}

void* cabeca(FilaCircular* fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia!\n");
        return NULL;
    }
    return fila->fila[fila->frente];
}

void* cauda(FilaCircular* fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia!\n");
        return NULL;
    }
    return fila->fila[fila->final];
}

bool estaVazia(FilaCircular* fila) {
    return fila->tamanho == 0;
}

bool cheia(FilaCircular* fila) {
    return fila->tamanho == fila->capacidade;
}

void mostrarFila(FilaCircular* fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }
    for (int i = 0; i < fila->tamanho; i++) {
        int indice = (fila->frente + i) % fila->capacidade;
        printf("%d ", *(int*)fila->fila[indice]);
    }
    printf("\n");
}

bool pesquisa(FilaCircular* fila, void* obj, int (*comparador)(void*, void*)) {
    for (int i = 0; i < fila->tamanho; i++) {
        int indice = (fila->frente + i) % fila->capacidade;
        if (comparador(fila->fila[indice], obj) == 0) {
            return true;
        }
    }
    return false;
}

int tamanho(FilaCircular* fila) {
    return fila->tamanho;
}

void liberaFila(FilaCircular* fila) {
    free(fila->fila);
    free(fila);
}

int comparadorInt(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FilaCircular* fila = criaFila(5);
    int a = 1, b = 2, c = 3;

    enfileira(fila, &a);
    enfileira(fila, &b);
    enfileira(fila, &c);

    mostrarFila(fila);
   
    printf("Cabeça: %d\n", *(int*)cabeca(fila));
    printf("Cauda: %d\n", *(int*)cauda(fila));

    printf("Desenfileirado: %d\n", *(int*)desenfileira(fila));
    mostrarFila(fila);

    printf("Pesquisando 2: %s\n", pesquisa(fila, &b, comparadorInt) ? "Encontrado" : "Não encontrado");
    printf("Tamanho atual: %d\n", tamanho(fila));

    liberaFila(fila);
    return 0;
}
