#include <stdio.h>
#include <ctype.h>

// Função para retornar o índice correspondente à primeira letra do nome
int indice(char *nome) {
    if (nome == NULL || nome[0] == '\0') {
        return -1;  // Retorna -1 se o nome for nulo ou vazio
    }
    
    char primeiraLetra = toupper(nome[0]); // Converte a primeira letra para maiúscula
    
    if (primeiraLetra < 'A' || primeiraLetra > 'Z') {
        return -1;  // Retorna -1 se a primeira letra não estiver entre 'A' e 'Z'
    }

    return primeiraLetra - 'A'; // Calcula o índice com base na primeira letra
}

int main() {
    // Exemplos de uso da função
    printf("Índice de 'Aline': %d\n", indice("Aline"));  // Saída esperada: 0
    printf("Índice de 'Beatriz': %d\n", indice("Beatriz")); // Saída esperada: 1
    printf("Índice de 'Carlos': %d\n", indice("Carlos")); // Saída esperada: 2
    printf("Índice de 'zuleika': %d\n", indice("zuleika")); // Saída esperada: 25
    printf("Índice de '123nome': %d\n", indice("123nome")); // Saída esperada: -1

    return 0;
}