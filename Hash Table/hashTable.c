#include <stdio.h>


#define TABLE_SIZE 5

int hashTable[TABLE_SIZE] = {0};
int numElements = 0;

void insert() {
    if (numElements == TABLE_SIZE) {
        printf("Hash table is full. Cannot insert more elements.\n");
        return;
    }

    int key, index, hkey;
    printf("Enter the element to insert: ");
    scanf("%d", &key);

    hkey = (key % TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;

        if (hashTable[index] == 0) {
            hashTable[index] = key;
            numElements++;
            printf("Element %d inserted at index %d\n", key, index);
            return;
        }
    }
}


void search() {
    int key, index, hkey;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    hkey = (key % TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE; 

        if (hashTable[index] == key) {
            printf("Element %d found at index %d\n", key, index); 
            return;
        }
    }

    printf("Element %d not found\n", key); 
}

void display(int hashTable[]) {
    printf("Index:\t");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", i);
    }

    printf("\nTable:\t");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", hashTable[i]); 
    }

    printf("\n");
}

int main() {
    int operation = 1;
    while (operation != 4) { 
        printf("Menu\n1.Insert\t2.Search\t3.Display\t4.Exit\n");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                display(hashTable); 
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
