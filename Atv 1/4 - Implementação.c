#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

// Função que calcula o índice do vetor com base na primeira letra do nome
int indice(const char *nome) {
    if (nome == NULL || nome[0] == '\0') {
        return -1;  // Retorna -1 se o nome for nulo ou vazio
    }
    
    char primeiraLetra = toupper(nome[0]); // Converte a primeira letra para maiúscula
    
    if (primeiraLetra < 'A' || primeiraLetra > 'Z') {
        return -1;  // Retorna -1 se a primeira letra não estiver entre 'A' e 'Z'
    }

    return primeiraLetra - 'A'; // Calcula o índice com base na primeira letra
}

// Função para adicionar um nome na estrutura, garantindo a classificação
void addName(NameList *indexArray, const char *name) {
    int index = indice(name);
    if (index == -1) {
        printf("Nome inválido: %s\n", name);
        return;
    }
    
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

// Função para pesquisar um nome na estrutura de dados
int searchName(NameList *indexArray, const char *name) {
    int index = indice(name);
    if (index == -1) return 0;

    Node *current = indexArray[index].head;
    while (current) {
        if (strcmp(current->name, name) == 0) return 1; // Encontrado
        current = current->next;
    }
    return 0; // Não encontrado
}

// Função para excluir um nome da estrutura de dados
void deleteName(NameList *indexArray, const char *name) {
    int index = indice(name);
    if (index == -1) return;

    Node *current = indexArray[index].head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (current->prev) current->prev->next = current->next;
            else indexArray[index].head = current->next;

            if (current->next) current->next->prev = current->prev;

            free(current);
            printf("Nome %s excluído.\n", name);
            return;
        }
        current = current->next;
    }
    printf("Nome %s não encontrado.\n", name);
}

// Função para renomear um nome na estrutura de dados
void renameName(NameList *indexArray, const char *oldName, const char *newName) {
    deleteName(indexArray, oldName);
    addName(indexArray, newName);
}

// Função para verificar se a estrutura está vazia
int isEmpty(NameList *indexArray) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (indexArray[i].head) return 0; // Encontrou um nome, não está vazia
    }
    return 1; // Estrutura vazia
}

// Função para contar a quantidade de nomes na estrutura
int countNames(NameList *indexArray) {
    int count = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        Node *current = indexArray[i].head;
        while (current) {
            count++;
            current = current->next;
        }
    }
    return count;
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

    addName(indexArray, "Aline");
    addName(indexArray, "Amanda");
    addName(indexArray, "Ana");
    addName(indexArray, "Bia");
    addName(indexArray, "Beatriz");
    addName(indexArray, "Carlos");

    printf("Estrutura de dados após inserções:\n");
    printNames(indexArray);

    printf("\nPesquisando 'Carlos': %s\n", searchName(indexArray, "Carlos") ? "Encontrado" : "Não encontrado");
    
    deleteName(indexArray, "Carlos");
    printf("\nEstrutura de dados após excluir 'Carlos':\n");
    printNames(indexArray);

    renameName(indexArray, "Ana", "Ana Paula");
    printf("\nEstrutura de dados após renomear 'Ana' para 'Ana Paula':\n");
    printNames(indexArray);

    printf("\nEstrutura de dados está vazia? %s\n", isEmpty(indexArray) ? "Sim" : "Não");
    printf("Quantidade de nomes: %d\n", countNames(indexArray));

    freeMemory(indexArray);
    return 0;
}