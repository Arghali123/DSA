#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct BST
{
    int data;
    struct BST *lchild,*rchild;
}node;

void insert(node *,node *);
void preorder(node *);
void inorder(node *);
void postorder(node *);
node *search(node *,int,node **);
node *delete_node(node *,int);
node *get_node();
node *find_min(node *);

void main()
{
    int choice;
    char ans='N';
    int key,dkey;
    node *new_node,*root,*temp,*parent;
    root=NULL;

    printf("\nProgram For Binary Search Tree.\n");
    do 
    {
        printf("\n1.) Create");
        printf("\n2.) Search");
        printf("\n3.) Recursive Traversal");
        printf("\n4.) Delete");
        printf("\n5.) Exit");
        
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                do
                {
                    new_node=get_node();
                    printf("Enter the element to be inserted: ");
                    scanf("%d",&new_node->data);
                    if(root==NULL)
                        root=new_node;
                    else
                        insert(root,new_node);
                    
                    printf("\nDo you want to enter more element?(y/n): ");
                    ans=getch();
                }while(ans=='y');
                break;

            case 2:
                printf("Enter Element to be searched: ");
                scanf("%d",&key);
                temp=search(root,key,&parent);
                if(temp!=NULL)
                {
                    if(parent!=NULL)
                        printf("\nParent of node %d is %d",temp->data,parent->data);
                    else
                        printf("\nNode %d is root, no parent.",temp->data);
                }
                else
                    printf("\nElement not found.");
                break;

            case 3:
                if(root==NULL)
                    printf("Tree is not Created.");
                else
                {
                    printf("\nThe Preorder display: ");
                    preorder(root);
                    printf("\nThe Inorder display: ");
                    inorder(root);
                    printf("\nThe Postorder display: ");
                    postorder(root);
                }
                break;

            case 4:
                printf("Enter element to delete: ");
                scanf("%d",&dkey);
                root = delete_node(root,dkey);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Option!!");
        }

    }while(choice!=5);
}

node *get_node()
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}

void insert(node *root,node *new_node)
{
    if(new_node->data<root->data)
    {
        if(root->lchild==NULL)
            root->lchild=new_node;
        else
            insert(root->lchild,new_node);
    } 
    else if(new_node->data >root->data)
    {
        if(root->rchild==NULL)
            root->rchild=new_node;
        else
            insert(root->rchild,new_node);
    }
}

node *search(node *root,int key,node **parent)
{
    node *temp=root;
    *parent=NULL;

    while(temp!=NULL)
    {
        if(temp->data==key)
            return temp;

        *parent=temp;
        if(key < temp->data)
            temp=temp->lchild;
        else
            temp=temp->rchild;
    }
    return NULL;
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}

node *find_min(node *root)
{
    while(root->lchild!=NULL)
        root=root->lchild;
    return root;
}

node *delete_node(node *root,int key)
{
    if(root==NULL)
    {
        printf("Element not found.\n");
        return root;
    }
    if(key < root->data)
        root->lchild = delete_node(root->lchild,key);
    else if(key > root->data)
        root->rchild = delete_node(root->rchild,key);
    else
    {
        // Case 1: No child
        if(root->lchild==NULL && root->rchild==NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if(root->lchild==NULL)
        {
            node *temp=root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild==NULL)
        {
            node *temp=root->lchild;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else
        {
            node *temp = find_min(root->rchild);
            root->data = temp->data;
            root->rchild = delete_node(root->rchild, temp->data);
        }
    }
    return root;
}

