#include <stdio.h>
#include <stdlib.h>
#include "../headers/permutacao.h"

// Troca os valores apontados por dois ponteiros
void trocar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// realiza a permutação dos n elementos de um dado vetor e retorna a menor distancia possivel
int obterMenorDistancia(int a[], int tamanho, int n, int x, int **distancias, int *melhorCaminho) {
    int menorDistancia = 0;

    for (int i = 0; i < tamanho; i++) {
        int distancia = 0;

        /**
         * Chama a propria função recursivamente com tamanho -1. Assim cada repetição 
         * será sempre uma unidade menor que a outra, com o número total de repeticões
         * no final sendo: tamanho x tamanho-1 x tamanho-2 x ... x 1 = tamanho! 
         * Se tamanho = 5, 5!=120 permutações
        */
        obterMenorDistancia(a, tamanho - 1, n, x, distancias, melhorCaminho);

        // Distancia de X até o primeiro elemento da permutação
        distancia+= distancias[x][a[0]];

        for(int k = 0; k < n; k++) {
            if( k+1 < n) {
                int cidadeA = a[k];
                int cidadeB = a[k+1];

                distancia+= distancias[cidadeA][cidadeB]; 
            };
            melhorCaminho[k] = a[k];
        }

        // Distancia da ultima cidade até X
        distancia+= distancias[a[n-1]][x];

        if(i == 0) {
            menorDistancia = distancia;
        } else {
            if(distancia < menorDistancia) {
                menorDistancia = distancia;
            }
        }
        
        // Realiza a permutação entre dois elementos, gerando uma nova combinação
        if (tamanho % 2 == 1) {
            trocar(&a[0], &a[tamanho - 1]);
        } else {
            trocar(&a[i], &a[tamanho - 1]);
        }
    }

    return menorDistancia;
}