#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
}struct node *start = NULL;

void insertAtFront(int data){
	struct node *temp = malloc(sizeof(struct node));
	temp->data=data;
	temp->link=start;
	start=temp;
}

void insertAtEnd(int data){
	struct node *temp = malloc(sizeof(Struct node));
	temp->data=data;
	temp->link=NULL;
	if(start == NULL){
		start=temp;
	}
	else{
		struct node *current = malloc(sizeof(struct node));
		while(current->link != NULL){
		
			current = temp->link;
		}
		current->link=temp;
	}
}

void insertAtPosition(int data, int pos) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (pos == 1) {
        insertAtFront(data);
    } else {
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

void deleteFromFront() {
    struct node *temp = start;
    if (temp == NULL) {
        printf("List is empty\n");
    } else {
        start = temp->link;
        free(temp);
    }
}
void deleteFromEnd(){
	struct node *current = start;
	if(current == NULL){
		printf("List is empty");
	}
	else{
		while(current->link!=NULL){]
			current = current->link;
		}
	}
}



