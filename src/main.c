#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "gerarValorAleatorio.h"
#include "permutacao.h"
/* MAT Lucas = 5793; Edmarcos = 5387; DAVI = 5368*/


int main() {
    int N;
    int mode;
    FILE *file;
    FILE *output;
    int **matriz;
    int proximaDistancia;
    int X = 5 + 7 + 9 + 3 + 5 + 3 + 8 + 7 + 5 + 3 + 6 + 8;
    // X = 69
    

    setlocale(LC_ALL, "en_US.utf8");

    printf("Como deseja preencher as distâncias?\n");
    printf("1 - Valores aleatórios\n");
    printf("2 - Ler arquivo\n");

    scanf("%d", &mode);

    if (mode == 1) {
        
        printf("Insira o N:\n");
        scanf("%d" , &N);

        X = X % N;
        srand(time(NULL));
        
        matriz = (int **)malloc(N * sizeof(int *));

        for (int i = 0; i < N; i++) {
            matriz[i] = (int *)malloc(N * sizeof(int));
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    matriz[i][j] = 0;
                }
                else {
                    matriz[i][j] = gerarValorAleatorio(1, 99);
                }
            }
        }
    }
    else if (mode == 2) {
        file = fopen("tests/test.txt", "r");
        fscanf(file, "%d", &N);
        X = X % N;

        if (N < 1) {
            printf("Tamanho invalido");
            exit(1);
        }

        if (file == NULL) {
            printf("Falha ao iniciar o arquivo");
            exit(1);
        }

        
        matriz = (int **)malloc(N * sizeof(int *));
        for (int i = 0; i < N; i++)
        {
            matriz[i] = (int *)malloc(N * sizeof(int));
        }



        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    matriz[i][j] = 0;
                }
                else {
                    fscanf(file, "%d", &proximaDistancia);
                    matriz[i][j] = proximaDistancia;
                }
            }
        }
        fclose(file);
    }
    
    else {
        printf("Opção inválida.");
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();

    int tamanho = N -1;
    int a[tamanho];
    
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (i != X) {
            a[count] = i;
            count++;
        }
    }

    int maxPermutas = 1;
    for (int i = 1; i <= tamanho; ++i) {
        maxPermutas *= i;
    }

    int * melhorCaminho  = (int *)malloc( tamanho * sizeof(int));
    int menorDistancia = permutar(a, tamanho, tamanho, X, matriz, melhorCaminho );

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Como deseja receber o resultado?\n");
    printf("1 - Pelo terminal\n");
    printf("2 - Por arquivo\n");

    mode = 0;

    scanf("%d", &mode);

    printf("%d", mode);

    switch (mode) {
    case 1:
        printf("Distâncias:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        printf("O melhor caminho é: ");
        printf("%d -> ", X);

        for(int i = 0; i<tamanho; i++){
            printf("%d -> ", melhorCaminho[i]);
        }

        printf("%d", X);

        printf("\n");

        printf("Menor Distancia: %d\n", menorDistancia);
        printf("Tempo de execução: %f segundos\n", cpu_time_used);
        break;
    case 2:
        output = fopen("tests/output.txt", "w");
        if(output == NULL){
            printf("Falha ao acessar o arquivo de Saida");
            return 1;
        }

        fprintf(output, "Distâncias:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                fprintf(output, "%d\t", matriz[i][j]);
            }
            fprintf(output, "\n");
        }

        fprintf(output, "\n");

        fprintf(output, "O melhor caminho é: ");
        fprintf(output, "%d -> ", X);

        for(int i = 0; i<tamanho; i++){
            fprintf(output, "%d -> ", melhorCaminho[i]);
        }
        
        fprintf(output, "%d", X);

        fprintf(output, "\n");

        fprintf(output, "Menor Distancia: %d \n", menorDistancia);
        fprintf(output, "Tempo de execução: %f segundos\n", cpu_time_used);

        fclose(output);
        break;
    default:
        printf("Opção inválida\n");
        break;
    }

    for (int i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
