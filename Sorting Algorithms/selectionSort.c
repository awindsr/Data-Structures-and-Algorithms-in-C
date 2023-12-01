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
    
    int min_index=0;
    count++;
    for(int i=0; i< totalNumberofElements; i++){
        min_index=i;
        count+=2;
        for(int j=i+1; j< totalNumberofElements; j++){
            count++;
            if (arr[j]<arr[min_index]){
                count++;
                min_index = j;
                count++;
                //3 2m 6 1
            }
            else{
                count++;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        count+=3;

        
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
