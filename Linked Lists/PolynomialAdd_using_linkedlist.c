#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

typedef struct Node Polynomial;

// Create poly
Polynomial* createPoly(int coeff, int exp) {
    Polynomial* newNode = (Polynomial*)malloc(sizeof(Polynomial));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert term
Polynomial* insertTerm(Polynomial* poly, int coeff, int exp, int degree) {
    Polynomial* term = createPoly(coeff, exp);
    if (poly == NULL) {
        return term;
    } else {
        Polynomial* current = poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = term;
        return poly;
    }
}

// Display poly
void displayPoly(Polynomial* poly) {
    if (poly == NULL) {
        printf("Empty polynomial\n");
    } else {
        while (poly != NULL) {
            printf("%dX^%d", poly->coeff, poly->exp);
            poly = poly->next;
            if (poly != NULL) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

/// Add polynomials
Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    if (poly1 == NULL) {
        return poly2;
    }
    if (poly2 == NULL) {
        return poly1;
    }

    Polynomial* resultHead = NULL;
    Polynomial* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        Polynomial* newNode = (Polynomial*)malloc(sizeof(Polynomial));

        if (poly1->exp > poly2->exp) {
            newNode->coeff = poly1->coeff;
            newNode->exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            newNode->coeff = poly2->coeff;
            newNode->exp = poly2->exp;
            poly2 = poly2->next;
        } else {
            newNode->coeff = poly1->coeff + poly2->coeff;
            newNode->exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        newNode->next = NULL;

        if (resultHead == NULL) {
            resultHead = newNode;
            result = resultHead;
        } else {
            result->next = newNode;
            result = result->next;
        }
    }

    // If there are remaining terms in poly1 or poly2
    while (poly1 != NULL) {
        Polynomial* newNode = (Polynomial*)malloc(sizeof(Polynomial));
        newNode->coeff = poly1->coeff;
        newNode->exp = poly1->exp;
        newNode->next = NULL;
        result->next = newNode;
        result = result->next;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        Polynomial* newNode = (Polynomial*)malloc(sizeof(Polynomial));
        newNode->coeff = poly2->coeff;
        newNode->exp = poly2->exp;
        newNode->next = NULL;
        result->next = newNode;
        result = result->next;
        poly2 = poly2->next;
    }

    return resultHead;
}




// Free polynomial
void freePolynomial(Polynomial* poly) {
    Polynomial* current = poly;
    while (current != NULL) {
        Polynomial* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Polynomial* poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice, coeff, exp, degree;

    do {
        printf("\nMenu:\n");
        printf("1. Enter polynomial 1\n");
        printf("2. Enter polynomial 2\n");
        printf("3. Display polynomial 1\n");
        printf("4. Display polynomial 2\n");
        printf("5. Add polynomials\n");
        printf("6. Display result\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the degree of the polynomial: ");
                scanf("%d", &degree);
                for (int i = 0; i <= degree; i++) {
                    printf("Enter coefficient and exponent of term %d for polynomial 1 (coeff exp): ", i + 1);
                    scanf("%d %d", &coeff, &exp);
                    poly1 = insertTerm(poly1, coeff, exp, degree);
                }
                break;

            case 2:
                printf("Enter the degree of the polynomial: ");
                scanf("%d", &degree);
                for (int i = 0; i <= degree; i++) {
                    printf("Enter coefficient and exponent for polynomial 2 (coeff exp): ");
                    scanf("%d %d", &coeff, &exp);
                    poly2 = insertTerm(poly2, coeff, exp, degree);
                }
                break;

            case 3:
                printf("Polynomial 1: ");
                displayPoly(poly1);
                break;

            case 4:
                printf("Polynomial 2: ");
                displayPoly(poly2);
                break;

            case 5:
                result = addPolynomials(poly1, poly2);
                printf("Polynomials added successfully.\n");
                break;

            case 6:
                printf("Resultant Polynomial: ");
                displayPoly(result);
                break;

            case 7:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 7);

    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}

