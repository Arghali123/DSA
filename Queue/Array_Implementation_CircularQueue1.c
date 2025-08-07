//Array implemenation of circular queue with sacrifying one cell in C.

#include<stdio.h>
#define SIZE 5

struct cqueue
{
    int item[SIZE];
    int rear;
    int front;
};

typedef struct cqueue qu;
void insert(qu *);
void display(qu *);
void delete(qu *);

int main()
{
 int ch;
 qu *q;
 q->front=SIZE-1;
 q->rear=SIZE-1;
 printf("Menu for prorgam.\n");
 printf("1.) Enqueue.\n");
 printf("2.) Dequeue.\n");
 printf("3.) Display.\n");
 printf("4.) Exit.\n");
 do
 {
    printf("Enter the choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
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
        return(1);

        default:
        printf("Invalid choice!!");
    }
 }while(ch<5);
 return 0;
}

void insert(qu *q)
{
    int d;
    if((q->rear+1)%SIZE==q->front)
    {
        printf("Queue is full.\n");
    }else
    {
        q->rear=(q->rear+1)%SIZE;
        printf("Enter data to be inserted: ");
        scanf("%d",&d);
        q->item[q->rear]=d;
    }
}

void delete(qu *q)
{
 if(q->rear==q->front)
 {
    printf("Queue is empty!!");
 }else
 {
    q->front=(q->front+1)%SIZE;
    printf("Deleted item is: %d\n",q->item[q->front]);
 }
}

void display(qu *q)
{
   int i;
   if(q->rear==q->front) 
   {
    printf("Queue is empty!!.\n");
   }else
   {
    printf("Items of queue are:\n");
    for(i=(q->front+1)%SIZE;i!=q->rear;i=(i+1)%SIZE)
    {
        printf("%d ",q->item[i]);
    }
    printf("%d ",q->item[q->rear]);
   }
}