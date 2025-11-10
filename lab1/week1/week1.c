#include <stdio.h>
#define s 2

int f = -1, r = -1;
int a[s];

void enq(int x) {
    if (r == s - 1) {
        printf("Queue is full\n");
    } else {
        if (f == -1) f = 0;
        a[++r] = x;
    }
}

void deq() {
    if (f == -1 || f > r) {
        printf("Empty queue\n");
    } else {
        printf("Dequeued: %d\n", a[f++]);
        if (f > r) {  // Reset when queue is empty after dequeue
            f = -1;
            r = -1;
        }
    }
}

void display() {
    if (f == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        for (int i = f; i <= r; i++) {
            printf("%d\n", a[i]);
        }
    }
}

int main() {
    char c;
    do {
        printf("\nEnter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf(" %c", &c);

        switch (c) {
            case '1': {
                int val;
                printf("Enter element: ");
                scanf("%d", &val);
                enq(val);
                break;
            }
            case '2':
                deq();
                break;
            case '3':
                display();
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (c != '4');

    return 0;
}
