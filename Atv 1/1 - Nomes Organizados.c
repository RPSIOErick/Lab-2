#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Estrutura do nó da lista duplamente encadeada
typedef struct Node {
    char name[50];
    struct Node *prev;
    struct Node *next;
} Node;

// Estrutura para armazenar a lista de nomes
typedef struct {
    Node *head;
} NameList;

// Função para inicializar as listas de nomes
void initializeLists(NameList *indexArray) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        indexArray[i].head = NULL;
    }
}

// Função para criar um novo nó
Node* createNode(const char *name) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Função para inserir o nome na posição correta da lista duplamente encadeada
void insertName(NameList *indexArray, const char *name) {
    int index = name[0] - 'A';  // Calcula o índice com base na inicial do nome
    Node *newNode = createNode(name);

    // Caso a lista esteja vazia
    if (!indexArray[index].head) {
        indexArray[index].head = newNode;
        return;
    }

    // Inserção ordenada na lista duplamente encadeada
    Node *current = indexArray[index].head;
    Node *prev = NULL;

    // Percorre a lista até encontrar a posição correta para inserir
    while (current && strcmp(current->name, name) < 0) {
        prev = current;
        current = current->next;
    }

    if (!prev) {
        // Inserção no início da lista
        newNode->next = indexArray[index].head;
        indexArray[index].head->prev = newNode;
        indexArray[index].head = newNode;
    } else {
        // Inserção entre dois nós ou no final da lista
        newNode->next = current;
        newNode->prev = prev;
        prev->next = newNode;
        if (current) {
            current->prev = newNode;
        }
    }
}

// Função para exibir a estrutura de dados
void printNames(NameList *indexArray) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (indexArray[i].head) {
            printf("%c -> ", 'A' + i);
            Node *current = indexArray[i].head;
            while (current) {
                printf("%s", current->name);
                if (current->next) {
                    printf(" -> ");
                }
                current = current->next;
            }
            printf("\n");
        }
    }
}

// Função para liberar memória
void freeMemory(NameList *indexArray) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        Node *current = indexArray[i].head;
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    NameList indexArray[ALPHABET_SIZE];
    initializeLists(indexArray);

    // Exemplo de nomes a serem adicionados
    insertName(indexArray, "Aline");
    insertName(indexArray, "Amanda");
    insertName(indexArray, "Ana");
    insertName(indexArray, "Ananda");
    insertName(indexArray, "Bia");
    insertName(indexArray, "Beatriz");
    insertName(indexArray, "Carla");
    insertName(indexArray, "Carlos");
    insertName(indexArray, "Cesar");
    insertName(indexArray, "Ronaldo");
    insertName(indexArray, "Cosmos");
    insertName(indexArray, "Debora");
    insertName(indexArray, "Enaldinho");
    insertName(indexArray, "Fabio");
    insertName(indexArray, "Fabiana");
    insertName(indexArray, "Zaza");
    insertName(indexArray, "Zoraide");
    insertName(indexArray, "Zuleika");

    // Exibe a estrutura de dados
    printNames(indexArray);

    // Libera a memória alocada
    freeMemory(indexArray);

    return 0;
}