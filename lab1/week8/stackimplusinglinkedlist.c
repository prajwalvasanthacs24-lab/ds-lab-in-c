#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* t = malloc(sizeof(struct Node));
    t->data = x;
    t->next = top;
    top = t;
}

int pop() {
    if (top == NULL) return -1;
    struct Node* t = top;
    int x = t->data;
    top = top->next;
    free(t);
    return x;
}

void display() {
    struct Node* t = top;
    if (!t) {
        printf("empty\n");
        return;
    }
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, x;

    while (1) {
        printf("\n1 push");
        printf("\n2 pop");
        printf("\n3 display");
        printf("\n4 exit");
        printf("\nenter: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("x: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                printf("pop: %d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("invalid\n");
        }
    }
}
