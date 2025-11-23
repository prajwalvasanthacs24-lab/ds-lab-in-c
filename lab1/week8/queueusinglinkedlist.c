#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* t = malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (rear == NULL) {
        front = rear = t;
    } else {
        rear->next = t;
        rear = t;
    }
}

int dequeue() {
    if (front == NULL) return -1;
    struct Node* t = front;
    int x = t->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(t);
    return x;
}

void display() {
    struct Node* t = front;
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
        printf("\n1 enqueue");
        printf("\n2 dequeue");
        printf("\n3 display");
        printf("\n4 exit");
        printf("\nenter: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("x: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                printf("dequeue: %d\n", dequeue());
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
