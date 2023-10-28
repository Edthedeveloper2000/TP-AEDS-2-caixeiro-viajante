#include <time.h>

void printArr(int a[], int n) {
    printf("---------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int heapPermutation(int a[], int size, int n) {
    int count = 0;

    if (size == 1) {
        printArr(a, n);
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