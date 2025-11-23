#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node *head = NULL, *tail = NULL;

void insert_front(int x) {
    struct Node* t = malloc(sizeof(struct Node));
    t->data = x;
    t->prev = NULL;
    t->next = head;
    if (head == NULL) {
        head = tail = t;
    } else {
        head->prev = t;
        head = t;
    }
}

void insert_end(int x) {
    struct Node* t = malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    t->prev = tail;
    if (tail == NULL) {
        head = tail = t;
    } else {
        tail->next = t;
        tail = t;
    }
}

int delete_front() {
    if (head == NULL) return -1;
    struct Node* t = head;
    int x = t->data;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    else
        head->prev = NULL;
    free(t);
    return x;
}

int delete_end() {
    if (tail == NULL) return -1;
    struct Node* t = tail;
    int x = t->data;
    tail = tail->prev;
    if (tail == NULL)
        head = NULL;
    else
        tail->next = NULL;
    free(t);
    return x;
}

void display() {
    struct Node* t = head;
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
        printf("\n1 insert front");
        printf("\n2 insert end");
        printf("\n3 delete front");
        printf("\n4 delete end");
        printf("\n5 display");
        printf("\n6 exit");
        printf("\nenter: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("x: ");
                scanf("%d", &x);
                insert_front(x);
                break;
            case 2:
                printf("x: ");
                scanf("%d", &x);
                insert_end(x);
                break;
            case 3:
                printf("deleted: %d\n", delete_front());
                break;
            case 4:
                printf("deleted: %d\n", delete_end());
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("invalid\n");
        }
    }
}
