#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_SIZE 100
#define MAX_STACK_SIZE 100

int isOperator(char c){
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char operation) {
    if (operation == '*' || operation == '/') return 2;
    if (operation == '+' || operation == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]){
	int stack[MAX_STACK_SIZE];
    int top = -1;
    int i, j;
       for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (c == ' ') continue; 
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        } else if (isOperator(c)) {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(c)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}
    	
void main(){
	char infix[MAX_EXPRESSION_SIZE], postfix[MAX_EXPRESSION_SIZE];
	
	printf("Enter infix expression: ");
	fgets(infix, sizeof(infix), stdin);
	
	infixToPostfix(infix, postfix);
	printf("Postfix expression is: %s\n", postfix);
}


































