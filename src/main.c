#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "headers/gerarValorAleatorio.h"
#include "headers/permutacao.h"
#define somaMatriculas 69

int main() {
    int N;
    int mode = 0;
    FILE *file;
    FILE *output;
    int **matriz;
    int proximaDistancia;
    int X;
    char file_path[250];

    setlocale(LC_ALL, "en_US.utf8");

    printf("Como deseja preencher as distâncias?\n");
    printf("1 - Valores aleatórios\n");
    printf("2 - Ler arquivo\n");

    scanf("%d", &mode);

    switch (mode) {
        case 1:
            printf("Insira o N:\n");
            scanf("%d", &N);
            srand(time(NULL));

            // Gera a matriz de distancias dinamicamente
            matriz = (int **)malloc(N * sizeof(int *));
            for (int i = 0; i < N; i++) {
                matriz[i] = (int *)malloc(N * sizeof(int));
            }

            // Monsta a matriz N x N com zeros nas diagonais
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == j) {
                        matriz[i][j] = 0;
                    } else {
                        matriz[i][j] = gerarValorAleatorio(1, 99);
                    }
                }
            }
            break;

        case 2:
            printf("Insira o caminho do arquivo: ");
            scanf("%s", file_path);

            file = fopen(file_path, "r");
            if (file == NULL) {
                printf("Falha ao abrir o arquivo");
                exit(1);
            }

            fscanf(file, "%d", &N);

            if (N < 1) {
                printf("Tamanho inválido");
                exit(1);
            }

            // Gera a matriz de distancias dinamicamente
            matriz = (int **)malloc(N * sizeof(int *));
            for (int i = 0; i < N; i++) {
                matriz[i] = (int *)malloc(N * sizeof(int));
            }

            // Monsta a matriz N x N com zeros nas diagonais
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == j) {
                        matriz[i][j] = 0;
                    } else {
                        fscanf(file, "%d", &proximaDistancia);
                        matriz[i][j] = proximaDistancia;
                    }
                }
            }
            fclose(file);
            break;
        default:
        printf("Opção inválida.");
            exit(1);
            break;
    }
    clock_t start, end;
    double cpu_time_used;
    X = somaMatriculas % N;
    start = clock();

    printf("Gerando resposta. Isso pode demorar um pouco...\n");

    int tamanho = N -1;
    int a[tamanho];
    
    int count = 0;

    // Gera lista de cidades de 0 a N
    for (int i = 0; i < N; i++) {
        if (i != X) {
            a[count] = i;
            count++;
        }
    }
    int * melhorCaminho  = (int *)malloc( tamanho * sizeof(int));
    int menorDistancia = permutar(a, tamanho, tamanho, X, matriz, melhorCaminho );

    end = clock();

    // Calcula tempo de execução
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Como deseja receber o resultado?\n");
    printf("1 - Pelo terminal\n");
    printf("2 - Por arquivo\n");

    mode = 0;

    scanf("%d", &mode);

    switch (mode) {
    case 1:
        // Exibe a matriz das distâncias
        printf("\nDistâncias:\n");
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

        // Escreve a matriz das distancias no arquivo
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

        // Escreve o menor caminho no arquivo
        for(int i = 0; i<tamanho; i++){
            fprintf(output, "%d -> ", melhorCaminho[i]);
        }
        
        fprintf(output, "%d", X);

        fprintf(output, "\n");

        fprintf(output, "Menor Distancia: %d \n", menorDistancia);
        fprintf(output, "Tempo de execução: %f segundos\n", cpu_time_used);

        fclose(output);

        printf("\nArquivo gerado com sucesso.\n");
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
