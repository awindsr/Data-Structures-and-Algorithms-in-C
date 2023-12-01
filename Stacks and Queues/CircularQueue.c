#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>

int MAX_SIZE; 
int *queue;
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}
bool isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full . Cannot enqueue %d\n", data);
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = data;
    printf("%d enqueued to the queue\n", data);
}
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    } else {
        int data = queue[front];
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return 0;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
    printf("Current front position: %d\n", front);
    printf("Current rear position: %d", rear);
    
}
int main() {
    int choice, data;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &MAX_SIZE);
    queue = (int *)malloc(MAX_SIZE * sizeof(int));
    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\t");
        printf("2. Dequeue\t");
        printf("3. Display\t");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
            	dequeue();
                printf("Dequeued\n");
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4); 
    free(queue); 
    return 0;
}

