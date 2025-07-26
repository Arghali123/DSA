#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node NodeType;
NodeType *first=NULL;
NodeType *last=NULL;
void display();

void insertBeg(int );
void insertEnd(int);

void deleteFirst();
void deleteLast();
int main()
{
    int choice;
    int item;
    printf("1. Insert at beginning\n");
    printf("2. Insert at End\n");
    printf("3. Delete First Node\n");
    printf("4. Delete Last Node\n");
    printf("4. Display\n");
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
            printf("Invalid choice Please enter correct choice.");
        }
    }while(choice<6);
    return 0;
}

void insertBeg(int item)
{
    NodeType *NewNode;
    NewNode=(NodeType *)malloc(sizeof(NodeType));
    NewNode->info=item;
    if(first==NULL)
    {
        NewNode->next=NewNode;
        first=NewNode;
        last=NewNode;
    }else
    {
        NewNode->next=first;
        first=NewNode;
        last->next=NewNode;
    }
}
void insertEnd(int item)
{
    NodeType *NewNode;
    NewNode=(NodeType *)malloc(sizeof(NodeType));
    NewNode->info=item;
    if(first==NULL)
    {
        first=NewNode;
        last=NewNode;
        NewNode->next=NewNode;
    }else
    {
        last->next=NewNode;
        last=NewNode;
        NewNode->next=first;
    }
}

void deleteFirst()
{
    NodeType *temp;
    temp=first;
    if(first==NULL)
    {
        printf("Empty linked List");
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
        free(temp);
    }
}
void deleteLast()
{
    NodeType *temp;

    if (last == NULL) {
        printf("Empty linked list\n");
        return;
    } else if (first == last) {
        free(last);
        first = last = NULL;
    } else {
        temp = first;
        while (temp->next != last) {
            temp = temp->next;
        }
        // Now temp is second-last node
        temp->next = first;
        free(last);       // free actual last node
        last = temp;      // update last to second-last node
    }
}

void display() {
    NodeType *temp;

    if (first == NULL) {
        printf("Empty linked list\n");
        return;
    }

    temp = first;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}