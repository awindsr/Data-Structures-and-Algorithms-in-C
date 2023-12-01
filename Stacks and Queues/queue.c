#include <stdio.h>

void enqueue(int queue[], int *front, int *rear, int data, int MAX_SIZE);
int dequeue(int queue[], int *front, int *rear);
void peek(int queue[], int *front, int *rear);
void display(int queue[], int front, int rear);

int main() {
    int MAX_SIZE, front = -1, rear = -1, operation, data;
    printf("Enter the max size: ");
    scanf("%d", &MAX_SIZE);
    int queue[MAX_SIZE];

    while (1) {
        printf("Select an operation:\n");
        printf("1. Enqueue\t2. Dequeue\t3. Display\t4. Peek\t5. Exit\n");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, &front, &rear, data, MAX_SIZE);
                break;
            case 2:
                data = dequeue(queue, &front, &rear);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                peek(queue, &front, &rear);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void enqueue(int queue[], int *front, int *rear, int data, int MAX_SIZE) {
    if (*rear > MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (*rear == -1) {
            *rear = 0;
            *front = 0;
        }
        queue[*rear] = data;
        (*rear)++;
    }
}

int dequeue(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int data = queue[*front];
        for (int i = 0; i < *rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        (*rear)--;
        if (*rear == 0) {
            *front = -1;
        }
        return data;
    }
}
void peek(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is empty. Cannot peek.\n");
    } else {
        printf("Front element of the queue: %d\n", queue[*front]);
    }
}

void display(int queue[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        for (int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

