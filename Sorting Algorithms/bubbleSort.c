#include <stdio.h>

void main(){
    int totalNumberofElements, count=0;
    count++;

    printf("Enter the total number of elements: ");
    scanf("%d", &totalNumberofElements);
    count++;

    int arr[totalNumberofElements];
    printf("Enter numbers: ");
    for(int i=0; i< totalNumberofElements; i++){
        count++;
        scanf("%d", &arr[i]);
        count++;
    }

    //bubble sort
    for (int i=0; i<totalNumberofElements; i++){
        count++;
        for (int j=0; j<totalNumberofElements; j++){
            count++;
            if(arr[i]<arr[j]){
                count++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                count+=3;
            }
        }
    }
    printf("Sorted array: ");
    for(int i=0; i< totalNumberofElements; i++){
        count++;
        printf("%d ", arr[i]);
        count++;
    }

    count+=2;
    printf("\nTime complexity is %d\nSpace Complexity is %d\n", count, 16+4*totalNumberofElements);
}