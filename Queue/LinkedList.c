#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NodeType;
NodeType *front=NULL;
NodeType *rear=NULL;


void insert(int);
void display();
void delete();

int main()
{
    int choice,item;
    do
    {
        printf("\n1.) Enqueue.\n");
        printf("2. Delete.\n");
        printf("3.) Display.\n");
        printf("4.) Exit.\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the data: ");
            scanf("%d",&item);
            insert(item);
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Invalid choice!!");
        }
    }while(choice<5);
    return 0;
}
void insert(int item)
{
 NodeType *Node;
 Node=(NodeType *)malloc(sizeof(NodeType));
 if(rear==NULL)
 {
    Node->info=item;
    Node->next=NULL;
    front=rear=Node;
 }else
 {
    Node->info=item;
    Node->next=NULL;
    rear->next=Node;
    rear=Node;
 }
}

void delete()
{
 NodeType *temp;
 if(front==NULL)
 {
    printf("Queue contains no element\n");
    return;
 }else if(front->next==NULL)
 {
    temp=front;
    front=rear=NULL;
    printf("Deleteted item is %d\n",temp->info);
    free(temp);
 }else
 {
    temp=front;
    front=front->next;
    printf("Deleted item is %d\n",temp->info);
    free(temp);
 }
}

void display()
{
    NodeType *temp;
    temp=front;
    printf("Queue items are: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
}