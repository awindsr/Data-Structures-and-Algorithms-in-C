#include <stdio.h>

void main() {
    int numberToSearch, elementCount, left = 0, right, count=0, flag=0;
    count+=3;

    printf("Enter the total number of elements: ");
    scanf("%d", &elementCount);
    count+=1;

    int array[elementCount];
    printf("Enter the elements: ");
    for (int i = 0; i < elementCount; i++) {
        count+=1;
        scanf("%d", &array[i]);
        count+=1;
    }

    //bubble sort
    for (int i = 0; i < elementCount - 1; i++) {
        count+=1;
        for (int j = 0; j < elementCount - i - 1; j++) {
            count+=1;
            if (array[j] > array[j + 1]) {
                count+=1;
                // Swap array[j] and array[j+1]
                int temp = array[j];
                count+=1;
                array[j] = array[j + 1];
                count+=1;
                array[j + 1] = temp;
                count+=1;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < elementCount; i++) {
        count+=1;
        printf("%d ", array[i]);
        count+=1;
    }
    printf("\n");

    printf("Enter the number to search for: ");
    scanf("%d", &numberToSearch);
    count+=1;

    right = elementCount - 1;
    count+=1;

    while (left <= right) {
        count+=1;
        int middle = left + (right) / 2;
        count+=1;

        if (numberToSearch < array[middle]) {
            count+=2;
            right = middle - 1;
            continue;

        } 
        if (numberToSearch > array[middle]) {
            count+=2;
            left = middle + 1;
            continue;
        } 
        else {
            printf("Number found at index %d\n", middle);
            flag=1;
            count+=2;
            break;
        }
    }
    if(flag==0){
        count++;
    printf("Number not found in the array.\n");
    }
    

    count+=2;
	printf("Time complexity is %d\nSpace Complexity is %d\n", count, 24+4*elementCount);
}
