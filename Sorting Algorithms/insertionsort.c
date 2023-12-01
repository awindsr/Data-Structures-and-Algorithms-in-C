#include <stdio.h>

void insertionSort(int arr[], int limit) {
    int key, i, j;

    for (i = 1; i < limit; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int limit;
    printf("Enter the total number of elements in the array: ");
    scanf("%d", &limit);

    int arr[limit];
    printf("Enter the elements: ");
    for (int i = 0; i < limit; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, limit);

    printf("Sorted array: ");
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

