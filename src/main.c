#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* MAT LUCAS = 5793; Edmarcos = 5387; DAVI = 53668*/
int main() {
    int N;
    int mode;
    FILE *file;
    int **matriz;
    int proximaDistancia;

    setlocale(LC_ALL, "en_US.utf8");

    printf("Como deseja preencher as distâncias?\n");
    printf("1 - Valores aleatórios\n");
    printf("2 - Ler arquivo\n");

    scanf("%d", &mode);

    if (mode == 1) {
    }
    else if(mode ==2) {
        file = fopen("tests/test.txt", "r");
        fscanf(file, "%d", &N);

        if(N < 1){
        printf("Tamanho invalido");
        exit(1);
        }

         if(file == NULL){
            printf("Falha ao iniciar o arquivo");
            exit(1);
        }

        matriz = (int **)malloc(N * sizeof(int *));

        for (int i = 0; i < N; i++) {
            matriz[i] = (int *)malloc(N * sizeof(int));
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j){
                    matriz[i][j] = 0;
                } else {
                    fscanf(file, "%d", &proximaDistancia);
                    matriz[i][j] = proximaDistancia;
               
            }
        }

        }

        printf("Distâncias:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", matriz[i][j]);
            }

            printf("\n");
        }
    printf("\n");
}  else {
    printf("Opcao invalida.");
    exit(1);
}

}
