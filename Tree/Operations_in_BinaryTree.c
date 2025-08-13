#include<stdio.h>
#include<stdlib.h>

struct tree {
    int info;
    struct tree *left;
    struct tree *right;
};

struct tree *insert(struct tree *, int);
struct tree *delete(struct tree *, int);
void preorder(struct tree *);
void inorder(struct tree *);
void postorder(struct tree *);
struct tree *search_and_replace(struct tree *);

int main() {
    struct tree *root = NULL;
    int choice;
    int item, item_no;

    do {
        printf("\n1.) Insert in Binary tree.\n");
        printf("2.) Pre-order traversal of Binary Tree.\n");
        printf("3.) In-order traversal of Binary Tree.\n");
        printf("4.) Post-order traversal of Binary Tree.\n");
        printf("5.) Delete From Binary tree.\n");
        printf("6.) Search and replace.\n");
        printf("7.) Exit.\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new element: ");
                scanf("%d", &item);
                root = insert(root, item);
                printf("The root is: %d\n", root->info);
                break;

            case 2:
                preorder(root);
                printf("\n");
                break;

            case 3:
                inorder(root);
                printf("\n");
                break;

            case 4:
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter the item to be deleted: ");
                scanf("%d", &item_no);
                root = delete(root, item_no);
                break;

            case 6:
                root = search_and_replace(root);
                break;

            case 7:
                exit(0);
                break;

            default:
                printf("Invalid option!!");
        }
    } while (choice < 8);

    return 0;
}

struct tree *insert(struct tree *root, int x) {
    if (!root) {
        root = (struct tree *)malloc(sizeof(struct tree));
        root->info = x;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (root->info > x) {
        root->left = insert(root->left, x);
    } else if (root->info < x) {
        root->right = insert(root->right, x);
    }
    return root;
}

void preorder(struct tree *root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void postorder(struct tree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right); // fixed: was calling preorder()
        printf("%d ", root->info);
    }
}

struct tree *delete(struct tree *ptr, int x) 
{
    struct tree *p1, *p2;

    if (!ptr) 
    {
        printf("\nNode not found\n");
        return ptr;
    }

    if (x < ptr->info) 
    {
        ptr->left = delete(ptr->left, x);
    } else if (x > ptr->info) 
    {
        ptr->right = delete(ptr->right, x);
    } else 
    { // found node
        if (ptr->left == NULL && ptr->right == NULL) 
        { // no children
            free(ptr);
            return NULL;
        } else if (ptr->left == NULL) 
        { // right child only
            p1 = ptr->right;
            free(ptr);
            return p1;
        } else if (ptr->right == NULL) 
        { // left child only
            p1 = ptr->left;
            free(ptr);
            return p1;
        } else 
        { // two children
            p1 = ptr->right;
            while (p1->left != NULL) 
            {
                p1 = p1->left;
            }
            ptr->info = p1->info; // replace with inorder successor
            ptr->right = delete(ptr->right, p1->info);
        }
    }
    return ptr;
}

struct tree *search_and_replace(struct tree *root) 
{
 int nkey,i,key;
 struct tree *ptr;
 ptr=root;
 printf("Enter the element to be searched: ");
 scanf("%d",&key);
 while(ptr)
 {
    if(key > ptr->info)
    {
        ptr=ptr->right;
    }else if(key < ptr->info)
    {
        ptr=ptr->left;
    }else
    {
        break;
    }
 }
 if(ptr)
 {
    printf("\nElement %d which was searched is found and is =%d",key,ptr->info);
    printf("Do you want to replace it, press 1 for yes: ");
    scanf("%d",&i);
    if(i==1)
    {
        printf("Enter new key: ");
        scanf("%d",&nkey);
        ptr->info=nkey;
    }else
    {
        printf("Its okey.\n");
    }
 }else
 {
    printf("Element %d does not exist in the binary tree",key);
 }
 return root;
}

