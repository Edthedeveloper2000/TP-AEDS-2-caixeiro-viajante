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
int permutar(int a[], int size, int n, int x, int **distancias) {
    int menorDistancia = 0;
    //int melhorTrajeto[n];
    for (int i = 0; i < size; i++) {
        int distancia = 0;
        permutar(a, size - 1, n, x, distancias);
        distancia+= distancias[x][a[0]];
        for(int k = 0; k < n; k++) {
            if( k+1 < n) {
                int cidadeA = a[k];
                int cidadeB = a[k+1];

                distancia+= distancias[cidadeA][cidadeB]; 
            };

             //printf("%d ", a[k]);
        }
        //printf("\n");

        distancia+= distancias[a[n-1]][x];
       // printf("%d", distancia);

        //printf("\n");

        if(i == 0) {
            menorDistancia = distancia;
        } else {
            if(distancia < menorDistancia) {
                menorDistancia = distancia;
            }
        }
        
        if (size % 2 == 1) {
            trocar(&a[0], &a[size - 1]);
        } else {
            trocar(&a[i], &a[size - 1]);
        }
    }

    return menorDistancia;
}