#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double myRandom() {
    return (double)rand() / RAND_MAX;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];


    int storeIndex = low + 1;

    for (int i = low + 1; i <= high; ++i) {
        if (arr[i] < pivot || (arr[i] == pivot && myRandom() < 0.5)) {
            swap(&arr[i], &arr[storeIndex]);
            ++storeIndex;
        }
    }

    swap(&arr[low], &arr[storeIndex - 1]);

    return storeIndex - 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    srand(time(NULL));

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

