#include<stdio.h>
#include<malloc.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node NodeType;
NodeType *first = NULL, *last = NULL;

//insert
void insert_atFirst(int item);
void insert_atEnd(int item);
void insert_givenPosition(int item,int pos);
void display();

//delete
void delete_first();
void delete_atLast();
void delete_nthnode();

void info_sum();
void count_nodes();

int main()
{
    int choice;
    int item;

    do
    {
        printf("\nMenu for program:\n");
        printf("1. Insert at first\n");
        printf("2. Insert at End\n");
        printf("3. Insert at given Postion\n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Delete nth node\n");
        printf("7. Info sum\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                insert_atFirst(item);
                display(); // Optional: to see current list
                break;

            case 2:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                insert_atEnd(item);
                display();
                break;

            case 3:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                int pos;
                printf("Enter position of a node at which you want to insert a new node: ");
                scanf("%d",&pos);
                insert_givenPosition(item,pos);
                display();
                break;

            case 4:
                delete_first();
                display();
                break;

            case 5:
                delete_atLast();
                display();
                break;

            case 6:
                delete_nthnode();
                display();
                break;

            case 7:
                info_sum();
                break;

            case 8:
                count_nodes();
                break;

            case 9:
                printf("Exiting program.\n");
                break;
            

            default:
                printf("Invalid choice\n");
        }

    } while (choice < 9);

    return 0;
}

void insert_atFirst(int item)
{
    NodeType *newNode = (NodeType*)malloc(sizeof(NodeType));
    newNode->info = item;

    if(first == NULL)
    {
        newNode->next = NULL;
        first = last = newNode;
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
}
void insert_atEnd(int item)
{
    NodeType *NewNode;
    NewNode=(NodeType *)malloc(sizeof(NodeType));
    NewNode->info=item;
    NewNode->next=NULL;
    if(first==NULL)
    {
        first=NewNode;
        last=NewNode;
    }else
    {
        last->next=NewNode;
        last=NewNode;
    }
}
void insert_givenPosition(int item,int pos)
{
    int i;
    NodeType *newnode,*temp;
    newnode=(NodeType *)malloc(sizeof(NodeType));
    newnode->info=item;
   
    if(first==NULL)
    {
        first=newnode;
        last=newnode;
    }else
    {
        temp=first;
        for(i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

//delete
void delete_first()
{
    NodeType *temp;
    if(first==NULL)
    {
        printf("Void deletion\n");
        return;
    }else
    {
        temp=first;
        first=first->next;
        free(temp);
    }
}
void delete_atLast()
{
    NodeType *hold, *temp;

    if (first == NULL)
    {
        printf("Void deletion\n");
        return;
    }
    else if (first->next == NULL)
    {
        hold = first;
        first = last = NULL;  // Also update 'last' to NULL
        free(hold);
    }
    else
    {
        temp = first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        hold = temp->next;
        temp->next = NULL;
        last = temp; // Update 'last' pointer
        free(hold);
    }
}
void delete_nthnode()
{
    NodeType *hold,*temp;
    int pos,i;
    if(first==NULL)
    {
        printf("Void deletion\n");
        return;
    }else
    {
        temp=first;
        printf("Enter the position of node which node is to be deleted: ");
        scanf("%d",&pos);
        for(i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        hold=temp->next;
        temp->next=hold->next;
        free(hold);
    }
}

void info_sum()
{
    NodeType *temp=first;
    int sum=0;
    while(temp!=NULL)
    {
      sum+=temp->info;
      temp=temp->next;
    }
    printf("Sum of info: %d\n",sum);
}
void count_nodes()
{
    int count=0;
    NodeType *temp;
    temp=first;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("Total nodes: %d\n",count);
}
void display()
{
    NodeType *temp = first;
    printf("List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}
