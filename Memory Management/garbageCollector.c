#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node {
    struct node* prev;
    int value;
    int size;
    struct node* next;
} node;

node* create() {
    node* new = malloc(sizeof(node));
    printf("Enter the value: ");
    scanf("%d", &(new->value));
    printf("Enter the size: ");
    scanf("%d", &(new->size));
    new->next = NULL;
    new->prev = NULL;
    return new;
}

node* insert(node* new, node* head) {
    if (head == NULL) {
        head = new;
    } else {
        node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
    return head;
}

node* insertGarbage(int p, node* head) {
    node* new = malloc(sizeof(node));
    new->next = NULL;
    new->prev = NULL;
    new->value = INT_MIN;
    new->size = p;

    if (head == NULL) {
        head = new;
    } else {
        node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
    return head;
}

void display(node* head) {
    printf("\nThe current list is         : ");
    node* temp = head;
    if (temp) {
        while (temp->next) {
            if (temp->value != INT_MIN) {
                printf("%d -> ", temp->value);
            } else {
                printf("# -> ");
            }
            temp = temp->next;
        }
        if (temp->value != INT_MIN) {
            printf("%d -> ", temp->value);
        } else {
            printf("# -> ");
        }
    }

    printf("\nThe corresponding sizes are : ");
    temp = head;
    if (temp) {
        while (temp->next) {
            printf("%d -> ", temp->size);
            temp = temp->next;
        }
        printf("%d -> ", temp->size);
    }
    printf("\n");
}

void displayGarbage(node* garbageHead) {
    printf("\nThe garbage values are : ");
    node* temp = garbageHead;
    if (temp) {
        while (temp->next) {
            printf("%d -> ", temp->size);
            temp = temp->next;
        }
        printf("%d -> ", temp->size);
    }
    printf("\n");
}

node* delete(node* head, node* garbageHead) {
    int pos;
    printf("Enter the position to delete : ");
    scanf("%d", &pos);
    node* temp = head;
    for (int i = 2; i <= pos; i++) {
        temp = temp->next;
    }
    if (temp->value != INT_MIN) {
        temp->value = INT_MIN;
        garbageHead = insertGarbage(temp->size, garbageHead);
    }
    display(head);
    return garbageHead;
}

void garbageCollection(node* head, node* garbageHead) {
    node* temp = head;
    int garbage = 0;
    if (temp) {
        while (temp->next) {
            if (temp->value == INT_MIN) {
                garbage += temp->size;
            }
            temp = temp->next;
        }
        if (temp->value == INT_MIN) {
            garbage += temp->size;
        }
    }
    printf("The amount of garbage collected is : %d\n", garbage);
    displayGarbage(garbageHead);
}

int main() {
    node* heapList = NULL;
    node* garbageList = NULL;
    int choice;

    while (1) {
        printf("\n\n============================");
        printf("\n1. Display\n2. Insert\n3. Delete\n4. Collect Garbage\n5. Exit");
        printf("\n============================");
        printf("\nEnter Choice : ");
        fflush(stdin);
        scanf("%d", &choice);
        node* newNode;

        switch (choice) {
            case 1:
                display(heapList);
                break;
            case 2:
                newNode = create();
                heapList = insert(newNode, heapList);
                display(heapList);
                break;
            case 3:
                garbageList = delete(heapList, garbageList);
                break;
            case 4:
                garbageCollection(heapList, garbageList);
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong option selected");
        }
    }
    return 0;
}
