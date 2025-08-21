#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
    int ht;
} node;

node *insert(node *, int);
node *delete(node *, int);

void preorder(node *);
void inorder(node *);

int height(node *);
int BF(node *);

node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);

int main()
{
    node *root = NULL;
    int x, op;
    do
    {
        printf("\n1.) Insert.");
        printf("\n2.) Delete.");
        printf("\n3.) Print.");
        printf("\n4.) Quit.");
        printf("\nEnter your choice: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter a data: ");
            scanf("%d", &x);
            root = insert(root, x);
            break;

        case 2:
            printf("Enter a data to delete: ");
            scanf("%d", &x);
            root = delete(root, x);
            break;

        case 3:
            printf("Preorder sequence:\n");
            preorder(root);
            printf("\nIn-order sequence:\n");
            inorder(root);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid option!!\n");
        }
    } while (op != 4);

    return 0;
}

// ---------- INSERT ----------
node *insert(node *T, int x)
{
    if (T == NULL)
    {
        T = (node *)malloc(sizeof(node));
        T->data = x;
        T->left = NULL;
        T->right = NULL;
        T->ht = 1;
    }
    else if (x > T->data)
    {
        T->right = insert(T->right, x);
        if (BF(T) == -2)
        {
            if (x > T->right->data)
                T = RR(T);
            else
                T = RL(T);
        }
    }
    else if (x < T->data)
    {
        T->left = insert(T->left, x);
        if (BF(T) == 2)
        {
            if (x < T->left->data)
                T = LL(T);
            else
                T = LR(T);
        }
    }
    else
    {
        printf("Duplicate value %d ignored.\n", x);
    }

    T->ht = height(T);
    return T;
}

// ---------- DELETE ----------
node *delete(node *T, int x)
{
    if (T == NULL)
        return NULL;

    if (x < T->data)
    {
        T->left = delete(T->left, x);
    }
    else if (x > T->data)
    {
        T->right = delete(T->right, x);
    }
    else
    {
        // Node found
        if (T->left == NULL && T->right == NULL)
        {
            free(T);
            return NULL;
        }
        else if (T->left == NULL)
        {
            node *temp = T->right;
            free(T);
            return temp;
        }
        else if (T->right == NULL)
        {
            node *temp = T->left;
            free(T);
            return temp;
        }
        else
        {
            node *p = T->right;
            while (p->left != NULL)
                p = p->left;
            T->data = p->data;
            T->right = delete(T->right, p->data);
        }
    }

    T->ht = height(T);

    int bf = BF(T);

    // Balance
    if (bf == 2)
    {
        if (BF(T->left) >= 0)
            return LL(T);
        else
            return LR(T);
    }
    if (bf == -2)
    {
        if (BF(T->right) <= 0)
            return RR(T);
        else
            return RL(T);
    }

    return T;
}

// ---------- UTILITIES ----------
int height(node *T)
{
    if (T == NULL)
        return 0;
    int lh = (T->left ? T->left->ht : 0);
    int rh = (T->right ? T->right->ht : 0);
    return (lh > rh ? lh : rh) + 1;
}

int BF(node *T)
{
    if (T == NULL)
        return 0;
    int lh = (T->left ? T->left->ht : 0);
    int rh = (T->right ? T->right->ht : 0);
    return lh - rh;
}

// ---------- ROTATIONS ----------
node *rotateright(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node *rotateleft(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node *RR(node *T)
{
    return rotateleft(T);
}

node *LL(node *T)
{
    return rotateright(T);
}

node *LR(node *T)
{
    T->left = rotateleft(T->left);
    return rotateright(T);
}

node *RL(node *T)
{
    T->right = rotateright(T->right);
    return rotateleft(T);
}

// ---------- TRAVERSALS ----------
void preorder(node *T)
{
    if (T != NULL)
    {
        printf("%d ", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(node *T)
{
    if (T != NULL)
    {
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}
-