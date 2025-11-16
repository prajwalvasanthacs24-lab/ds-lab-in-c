#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

struct node* newnode(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    return n;
}

void insert1(int x) {
    struct node *n = newnode(x);
    n->next = head1;
    head1 = n;
}

void insert2(int x) {
    struct node *n = newnode(x);
    n->next = head2;
    head2 = n;
}

void display(struct node *h) {
    struct node *p = h;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void reverse(struct node **h) {
    struct node *prev = NULL, *cur = *h, *next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *h = prev;
}

struct node* merge(struct node *a, struct node *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data <= b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

void split(struct node *src, struct node **f, struct node **b) {
    struct node *slow = src, *fast = src->next;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *f = src;
    *b = slow->next;
    slow->next = NULL;
}

void sort(struct node **h) {
    struct node *a, *b;
    if (*h == NULL || (*h)->next == NULL) return;
    split(*h, &a, &b);
    sort(&a);
    sort(&b);
    *h = merge(a, b);
}

void concat() {
    if (head1 == NULL) {
        head1 = head2;
        head2 = NULL;
        return;
    }
    struct node *p = head1;
    while (p->next) p = p->next;
    p->next = head2;
    head2 = NULL;
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1 Insert in List1\n2 Insert in List2\n3 Display List1\n4 Display List2\n5 Reverse List1\n6 Sort List1\n7 Concatenate List2 to List1\n8 Exit\n");
        scanf("%d", &ch);
        if (ch == 8) break;

        switch (ch) {
            case 1: printf("Enter: "); scanf("%d", &x); insert1(x); break;
            case 2: printf("Enter: "); scanf("%d", &x); insert2(x); break;
            case 3: display(head1); break;
            case 4: display(head2); break;
            case 5: reverse(&head1); break;
            case 6: sort(&head1); break;
            case 7: concat(); break;
        }
    }
    return 0;
}
