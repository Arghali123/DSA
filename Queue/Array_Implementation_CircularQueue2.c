#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct cqueue {
    int item[SIZE];
    int rear;
    int front;
};

typedef struct cqueue qu;
int count = 0;

void insert(qu*);
void display(qu*);
void delete(qu *);

int main() {
    int ch;
    qu *q = (qu*)malloc(sizeof(qu));  // ✅ Memory allocated
    q->front = SIZE - 1;
    q->rear = SIZE - 1;

    printf("Menu for the Program.\n");
    do {
        printf("\n1.) Enqueue.\n");
        printf("2.) Dequeue.\n");
        printf("3.) Display\n");
        printf("4.) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
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
               break;
            
            default:
                printf("Invalid option!!\n");
        }
    } while(ch < 5);

    return 0;
}

void insert(qu *q) {
    int d;
    if(count == SIZE) {
        printf("Queue is full.\n");
    } else {
        q->rear = (q->rear + 1) % SIZE;
        printf("Enter data to be inserted: ");
        scanf("%d", &d);
        q->item[q->rear] = d;
        count++;
    }
}

void delete(qu *q)
{
  if(count==0)
  {
    printf("Queue is empty.\n");
  }else
  {
    q->front=(q->front+1)%SIZE;
    printf("Deleted item is: %d\n",q->item[q->front]);
    count--;
  }
}
void display(qu *q) {
    if(count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Items of queue are:\n");
    int i = (q->front + 1) % SIZE;
    for(int c = 0; c < count; c++) {
        printf("%d ", q->item[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
