#include <stdio.h>
#include <stdlib.h>

// Função para imprimir as combinações
void mostrarCombinacoes(int **result, int count, int n) {
    printf("Todas as combinações:\n");
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Função para trocar os valores de dois inteiros
void trocar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Função para preencher o array de ponteiros com as combinações
int permutar(int a[], int size, int n, int **result, int count) {
    if (size == 1) {
        result[count] = (int *)malloc(n * sizeof(int));
        if (result[count] == NULL) {
            printf("Erro de alocação de memória.\n");
            exit(1);
        }
        for (int i = 0; i < n; i++) {
            result[count][i] = a[i];
        }
        return count + 1;
    }

    for (int i = 0; i < size; i++) {
        count = permutar(a, size - 1, n, result, count);

        if (size % 2 == 1) {
            trocar(&a[0], &a[size - 1]);
        } else {
            trocar(&a[i], &a[size - 1]);
        }
    }

    return count;
}