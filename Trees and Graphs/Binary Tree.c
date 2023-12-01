#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];
int current_index = 0;

void insert(int data){
	if (current_index < MAX_SIZE){
		tree[current_index] = data;
		current_index++;
	}
	else{printf("Tree is full. No more insertion possible.");}
}
void display(int position, int tree[]){
    if (position < current_index) {
        printf("Element at position %d is: %d\n", position, tree[position]);
        if (position == 0) {
            printf("It is root\n");
            printf("Left child of %d is: %d\n", tree[position], tree[position * 2 + 1]);
            printf("Right child of %d is: %d\n", tree[position], tree[position * 2 + 2]);   
        } else {
            int parent = (position - 1) / 2;
            printf("Parent of %d is: %d\n", tree[position], tree[parent]);
            if (position * 2< current_index) {
                printf("Left child of %d is: %d\n", tree[position], tree[position * 2 + 1]);
            } else {
                printf("There are no left child for %d\n", tree[position]);
            }
            if (position * 2 + 1 < current_index) {
                printf("Right child of %d is: %d\n", tree[position], tree[position * 2 + 2]);
            } else {
                printf("There are no right child for %d\n", tree[position]);
            }
        }
    } else {
        printf("No element at position %d\n", position);
    }
}
void main(){
	int size, i, data, position;
	bool flag = true;
	char choice;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    printf("Enter the elements of the array: ");
    for(i = 0; i<size; i++){
    	scanf("%d", &data);
    	insert(data);
    }
    
   while(flag == true){
    printf("Enter position  you want to check: ");
    scanf("%d", &position);

    display(position, tree);

    printf("Do you want to continue (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'n'){
        flag = false;
    }
}  
}
