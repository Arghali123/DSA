#include <stdio.h>

#define SIZE 20

struct queue {
    int item[SIZE];
    int rear;
    int front;
};

typedef struct queue qu;

void insert(qu *);
void delete(qu *);
void display(qu *);

int main() {
    int ch;
    qu q;           // ✅ Use actual structure instead of pointer
    q.front = 0;
    q.rear = -1;

    printf("Menu for program.\n");
    printf("1.) Insert.\n");
    printf("2.) Delete.\n");
    printf("3.) Display.\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                insert(&q);
                break;

            case 2:
                delete(&q);
                break;

            case 3:
                display(&q);
                break;

            default:
                printf("Your choice is wrong!!\n");
        }
    } while(ch < 4);

    return 0;
}

void insert(qu *q) {
    int d;
    if (q->rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        printf("Enter data to be inserted: ");
        scanf("%d", &d);
        q->rear++;
        q->item[q->rear] = d;
    }
}

void delete(qu *q) {
    int d;
    if (q->rear < q->front) {
        printf("Queue is empty.\n");
    } else {
        d = q->item[q->front];
        q->front++;
        printf("Deleted item is: %d\n", d);
    }
}

void display(qu *q) {
    if (q->rear < q->front) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d\t", q->item[i]);
        }
        printf("\n");
    }
}
