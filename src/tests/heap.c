#include <stdio.h>
#include <time.h>

// Função para gerar permutações usando o algoritmo de Heap
int heapPermutation(int a[], int size, int n) {
    int count = 0; // Inicializa o contador de permutações

    if (size == 1) {
        count++;
        return count;
    }

    for (int i = 0; i < size; i++) {
        count += heapPermutation(a, size - 1, n);

        if (size % 2 == 1) {
            int temp = a[0];
            a[0] = a[size - 1];
            a[size - 1] = temp;
        } else {
            int temp = a[i];
            a[i] = a[size - 1];
            a[size - 1] = temp;
        }
    }

    return count;
}

int main() {
    int n;
    printf("Digite um número para gerar as permutações: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Marca o início do relógio

    int totalPermutations = heapPermutation(a, n, n);

    end = clock(); // Marca o final do relógio

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("O número total de permutações é: %d\n", totalPermutations);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);
    return 0;
}
