#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start = NULL;

void insertAtFront(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = start;
    start = temp;
}

void insertAtEnd(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        struct node *current = start;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = temp;
    }
}

void insertAtPosition(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

     if (start == NULL) {
        insertAtFront(data);
    } 
    else{
    	int pos;
			printf("Enter the position to insert: ");
		    scanf("%d", &pos);
		    if (pos == 1) {
		    insertAtFront(data);
			}
			else {
		    struct node *current = start;
		    int i = 1;
		    while (i < pos - 1 && current->link != NULL) {
		        current = current->link;
		        i++;
		    }

		    if (current->link == NULL) {
		        current->link = temp;
		    } else {
		        temp->link = current->link;
		        current->link = temp;
		    }
   }
        
        
  }
    
}

void deleteFromFront() {
    struct node *temp = start;
    if (temp == NULL) {
        printf("List is empty\n");
    } else {
        start = temp->link;
        free(temp);
    }
}

void deleteFromEnd() {
    struct node *current = start;
    if (current == NULL) {
        printf("List is empty\n");
    } else {
        while (current->link->link != NULL) {
            current = current->link;
        }
        struct node *temp = current->link;
        current->link = NULL;
        free(temp);
    }
}

void deleteFromPosition(int pos) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        deleteFromFront();
    } else {
        struct node *current = start;
        struct node *previous = NULL;
        int i = 1;

        while (i < pos && current != NULL) {
            previous = current;
            current = current->link;
            i++;
        }

        if (current == NULL) {
            printf("Can't delete from this position\n");
        } else {
            previous->link = current->link;
            free(current);
            printf("Deletion element at position %d.\n", pos);
        }
    }
}


void display() {
    struct node *current = start;
    if (current == NULL) {
        printf("List is empty\n");
    } else {
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->link;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n1. Insert at front\n2. Insert at end\n3. Insert at position\n4. Delete from front\n5. Delete from end\n6. Delete from position\n7. Display\n8. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 2:
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
            	printf("Enter the data to insert : ");
                scanf("%d", &data);
                insertAtPosition(data);
                break;
            case 4:
                deleteFromFront();
                printf("Deletion successful.");
                break;
            case 5:
                deleteFromEnd();
                printf("Deletion successful.");
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                printf("Deletion element at position %d.", pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
        }
    }

    return 0;
}

