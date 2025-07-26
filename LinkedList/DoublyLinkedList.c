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
void insetEnd(int);

//delete
void deleteFirst();
void deleteEnd();

int main()
{
    int choice;
    int item;
    printf("1. Insert at Beginning.\n");
    printf("2. Insert at End.\n");
    printf("3. Delete First Node.\n");
    printf("4. Delete Last Node.\n");
    printf("5. Display.\n");
    do
    {
      printf("Enter your choice: ");
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
        insetEnd(item);
        break;

        case 3:
        deleteFirst();
        break;

        case 4:
        deleteEnd();
        break;

        case 5:
        display();
        break;

        default:
        printf("Invalid choice Plz enter correct choice!!");
      }
    }while(choice<6);
}

void insertBeg(int item)
{
    NodeType *Newnode;
    Newnode=(NodeType *)malloc(sizeof(NodeType));
    Newnode->info=item;
    Newnode->prev=Newnode->next=NULL;

    if(first==NULL)
    {
        first=Newnode;
        last=Newnode;
    }else
    {
        Newnode->next=first;
        first->prev=Newnode;
        first=Newnode;
    }
}
void insetEnd(int item)
{
 NodeType *Newnode;
 Newnode=(NodeType *)malloc(sizeof(NodeType));
 Newnode->info=item;
 Newnode->prev=Newnode->next=NULL;

 if(first==NULL)
 {
    first=Newnode;
    last=Newnode;
 }else
 {
    last->next=Newnode;
    Newnode->prev=last;
    last=Newnode;
 }
}

void deleteFirst()
{
  NodeType *temp;
  temp=first;
  if(first==NULL)
  {
    printf("Empty Linked List\n");
    return;
  }else if(first==last)
  {
    first=NULL;
    last=NULL;
    free(temp);
  }else
  {
    first=first->next;
    free(temp);
  }
}
void deleteEnd()
{
    NodeType *temp,*hold;
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
        hold=temp->next;
        temp->next=NULL;
        last=temp;
        free(hold);
    }
}

void display() {
    NodeType *temp;

    if (first == NULL) {
        printf("Empty linked list\n");
        return;
    }

    temp = first;
    printf("Doubly Linked List: ");
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}