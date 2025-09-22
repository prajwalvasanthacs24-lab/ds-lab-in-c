#include <stdio.h>

void push(int* a, int* top, int size);
void pop(int* a, int* top);
void display(int* a, int top);

int main() {
    int size;
    printf("Enter size of the stack: ");
    scanf("%d", &size);

    int a[size];
    int top = -1;

    int choice;
    do {
        printf("\nChoose an option: \n");
        printf("1 for Push element \n");
        printf("2 for Pop element \n");
        printf("3 for Display stack \n");
        printf("4 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push(a, &top, size);
                break;
            case 2:
                pop(a, &top);
                break;
            case 3:
                display(a, top);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Wrong choice .\n");
        }
    } while (choice != 4);

    return 0;
}

void push(int* a, int* top, int size) {
    int g;
    if (*top < size - 1) {
        printf("Enter an element to push: ");
        (*top)++;
        scanf("%d", &g);
        a[*top] = g;
        printf("Element pushed: %d\n", g);
    } else {
        printf("Stack overflow!\n");
    }
}

void pop(int* a, int* top) {
    if (*top == -1) {
        printf("Stack underflow\n");
    } else {
        int p = a[*top];
        printf("Popped element: %d\n", p);
        (*top)--;
}}

void display(int* a, int top) {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Current stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

