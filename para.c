#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int is_matching_pair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int is_balanced(const char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char top_char = pop();
            if (!is_matching_pair(top_char, c)) {
                return 0; // Not balanced
            }
        }
    }
    return top == -1; // Balanced if stack is empty
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0'; // Remove trailing newline

    if (is_balanced(expr)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}

