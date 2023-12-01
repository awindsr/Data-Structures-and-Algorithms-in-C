#include <stdio.h>

void push(int number, int stack[], int MAX_SIZE, int *top);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int MAX_SIZE, int top);

int main() {
    int operation, MAX_SIZE, number, top = -1;

    printf("Enter the max size of the stack: ");
    scanf("%d", &MAX_SIZE);

    int stack[MAX_SIZE];

    printf("Select an operation\n1.Push\t2.Pop\t3.Peek\t4.Display\t5.Exit\n");
	scanf("%d", &operation);
    while (operation!=5) {
        

        switch (operation) {
            case 1: {
                printf("Enter a number to push: ");
                scanf("%d", &number);
                push(number, stack, MAX_SIZE, &top);
                break;
            }
            case 2: {
                pop(stack, &top);
                break;
            }
            case 3: {
                peek(stack, top);
                break;
            }
            case 4: {
                display(stack, MAX_SIZE, top);
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
        printf("\nSelect an operation\n1.Push\t2.Pop\t3.Peek\t4.Display\t5.Exit\n");
		scanf("%d", &operation);
    }
}

void push(int number, int stack[], int MAX_SIZE, int *top) {
    if (*top >= MAX_SIZE - 1) {
        printf("Overflow\n\n");
    } else {
        (*top)++;
        printf("pushed value: %d\n", number);
        stack[*top] = number;
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Underflow\n\n");
        return;
    } else {
    	printf("Popped value: %d\n", stack[*top]);
        stack[*top] = 0;
        (*top)--;
    }
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n\n");
    } else {
        printf("Top value is %d\n", stack[top]);
    }
}

void display(int stack[], int MAX_SIZE, int top) {
    if (top == -1) {
        printf("Stack is empty\n\n");
    } else {
    	printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

