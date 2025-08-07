#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct cqueue {
    int item[SIZE];
    int front;
    int rear;
};

typedef struct cqueue pq;

void insert(pq *);
void delete(pq *);
void display(pq *);

int main() {
    int ch;
    pq *q = (pq *)malloc(sizeof(pq));
    q->front = 0;
    q->rear = -1;

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue (min priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert(q);
                break;
            case 2:
                delete(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}

void insert(pq *q) {
    int d;
    if (q->rear == SIZE - 1) {
        printf("Queue is full.\n");
    } else {
        printf("Enter data to be inserted: ");
        scanf("%d", &d);
        q->rear++;
        q->item[q->rear] = d;
    }
}

void delete(pq *q) {
    if (q->rear < q->front) {
        printf("Queue is empty.\n");
        return;
    }

    int minIndex = q->front;
    for (int i = q->front + 1; i <= q->rear; i++) {
        if (q->item[i] < q->item[minIndex]) {
            minIndex = i;
        }
    }

    int deletedValue = q->item[minIndex];

    // Shift elements to the left
    for (int i = minIndex; i < q->rear; i++) 
    {
        q->item[i] = q->item[i + 1];
    }

    q->rear--;

    printf("Deleted minimum value: %d\n", deletedValue);

    // Reset queue if empty
    if (q->rear < q->front) {
        q->front = 0;
        q->rear = -1;
    }
}

void display(pq *q) {
    if (q->rear < q->front) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->item[i]);
        }
        printf("\n");
    }
}
