#include <stdio.h>

void main(){
	int numberToSearch, flag=0, count=0, elementCount;
	count+=2;
	
	printf("Enter the total number of elements: ");
	scanf("%d", &elementCount);
	count++;
	
	int array[elementCount];
	
	printf("Enter elements: ");
	for(int i=0; i<elementCount; i++){
		count++;
		scanf("%d", &array[i]);
		count++;
	} 	
	
	printf("Enter element to search for: ");
	scanf("%d", &numberToSearch);
	count++;
	
	for(int i=0; i<elementCount; i++){
		count++;
		if(array[i] == numberToSearch){
			count++;
			flag = 1;
			count++;
			printf("Number found at %d\n",i);
			count++;
		}
		
	}
	if (flag==0){
		count++;
		printf("Element not found\n");
	}
	count+=2;
	printf("Time complexity is %d\nSpace Complexity is %d\n", count, 20+4*elementCount);
}
