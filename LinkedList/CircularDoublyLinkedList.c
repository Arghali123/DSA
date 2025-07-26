#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
typedef struct node NodeType;
NodeType *first=NULL;
NodeType *last=NULL;

void display();

//insert
void insertBeg(int);
void insertEnd(int);

//delete
void deleteFirst();
void deleteLast();

int main()
{
    int choice;
    int item;
    printf("1. Insert at Beginning.\n");
    printf("2. Insert at Last.\n");
    printf("3. Delete node first.\n");
    printf("4. Delete node last.\n");
    printf("5. Display.\n");
    do
    {
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter data item to be inserted: ");
            scanf("%d",&item);
            insertBeg(item);
            break;

            case 2:
            printf("Enter data item to be inserted: ");
            scanf("%d",&item);
            insertEnd(item);
            break;

            case 3:
            deleteFirst();
            break;

            case 4:
            deleteLast();
            break;

            case 5:
            display();
            break;

            default:
            printf("Invalid choice Plz enter correct choice!!");
        }
    }while(choice < 6);
}

void insertBeg(int item)
{
  NodeType *Newnode;
  Newnode=(NodeType *)malloc(sizeof(NodeType));
  Newnode->info=item;
  if(first==NULL)
  {
    first=Newnode;
    last=Newnode;
    Newnode->next=Newnode;
    Newnode->prev=Newnode;
  }else
  {
    Newnode->next=first;
    first->prev=Newnode;
    first=Newnode;
    last->next=first;
    first->prev=last;
  }
}
void insertEnd(int item)
{
 NodeType *Newnode;
 Newnode=(NodeType *)malloc(sizeof(NodeType));
 Newnode->info=item;
 if(first==NULL)
 {
    first=Newnode;
    last=Newnode;
    Newnode->next=Newnode;
    Newnode->prev=Newnode;
 }else
 {
    last->next=Newnode;
    Newnode->prev=last;
    last=Newnode;
    last->next=first;
    first->prev=last;
 }
}

void deleteFirst()
{
    NodeType *temp;
    temp=first;
    if(first==NULL)
    {
        printf("Empty Linked List.\n");
        return;
    }else if(first==last)
    {
        first=NULL;
        last=NULL;
        free(temp);
    }else
    {
        first=first->next;
        last->next=first;
        first->prev=last;
        free(temp);
    }
}
void deleteLast()
{
   NodeType *temp;
   temp=first;
   if(last==NULL)
   {
    printf("Empty Linked List.\n");
    return;
   }else if(first==last)
   {
    first=NULL;
    last=NULL;
    free(temp);
   }else
   {
    while(temp->next!=last)
    {
        temp=temp->next;
    }
    last=temp;
    last->next=first;
    first->prev=last;
    free(temp->next);
   }
}
void display() {
    NodeType *temp;

    if (first == NULL) {
        printf("Empty linked list\n");
        return;
    }

    temp = first;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}
