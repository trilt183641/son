// C program to insert a node_Tree in AVL tree
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// An AVL tree node_Tree
typedef struct Node_Tree
{
    int key;
    int value;
    struct Node_Tree *left;
    struct Node_Tree *right;
    int height;
}Map;

// A utility function to get Maximum of two integers
int Max(int a, int b);

// A utility function to get the height of the tree
int height(struct Node_Tree *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get Maximum of two integers
int Max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Helper function that allocates a new node_Tree with the given key and 
	NULL left and right pointers. */
struct Node_Tree *newNode_Tree(int key, int value)
{
    struct Node_Tree *node_Tree = (struct Node_Tree *)
        malloc(sizeof(struct Node_Tree));
    node_Tree->key = key;
    node_Tree->value = value;
    node_Tree->left = NULL;
    node_Tree->right = NULL;
    node_Tree->height = 1; // new node_Tree is initially added at leaf
    return (node_Tree);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node_Tree *rightRotate(struct Node_Tree *y)
{
    struct Node_Tree *x = y->left;
    struct Node_Tree *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = Max(height(y->left), height(y->right)) + 1;
    x->height = Max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node_Tree *leftRotate(struct Node_Tree *x)
{
    struct Node_Tree *y = x->right;
    struct Node_Tree *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = Max(height(x->left), height(x->right)) + 1;
    y->height = Max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node_Tree N
int getBalance(struct Node_Tree *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node_Tree and returns the new root of the subtree.
struct Node_Tree *insert(struct Node_Tree *node_Tree, int key, int value)
{
    /* 1. Perform the normal BST insertion */
    if (node_Tree == NULL)
        return (newNode_Tree(key, value));

    if (key < node_Tree->key)
        node_Tree->left = insert(node_Tree->left, key, value);
    else if (key > node_Tree->key)
        node_Tree->right = insert(node_Tree->right, key, value);
    else // Equal keys are not allowed in BST
        return node_Tree;

    /* 2. Update height of this ancestor node_Tree */
    node_Tree->height = 1 + Max(height(node_Tree->left),
                           height(node_Tree->right));

    /* 3. Get the balance factor of this ancestor 
		node_Tree to check whether this node_Tree became 
		unbalanced */
    int balance = getBalance(node_Tree);

    // If this node_Tree becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node_Tree->left->key)
        return rightRotate(node_Tree);

    // Right Right Case
    if (balance < -1 && key > node_Tree->right->key)
        return leftRotate(node_Tree);

    // Left Right Case
    if (balance > 1 && key > node_Tree->left->key)
    {
        node_Tree->left = leftRotate(node_Tree->left);
        return rightRotate(node_Tree);
    }

    // Right Left Case
    if (balance < -1 && key < node_Tree->right->key)
    {
        node_Tree->right = rightRotate(node_Tree->right);
        return leftRotate(node_Tree);
    }

    /* return the (unchanged) node_Tree pointer */
    return node_Tree;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node_Tree
void preOrder(struct Node_Tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Driver program to test above function*/

int findKey(struct Node_Tree *root, int key)
{
    printf("done\n");
    struct Node_Tree *p = root;
    while (1)
    {
        if (key > p->key)
        {
            if (p->right != NULL)
                p = p->right;
            else
            {
                return -1;
            }
        }
        else if (key < p->key)
        {
            if (p->left != NULL)
                p = p->left;
            else
            {
                return -1;
            }
        }
        else
            return p->value;
    }
    return -1;
    printf("done\n");
}

// int main()
// {
//     struct Node_Tree *root = NULL;
//     clock_t start, end;
//     /* Constructing tree given in the above figure */
//     // root = insert(root, 10, 4);
//     // root = insert(root, 20, 7);
//     // root = insert(root, 30, 8);
//     // root = insert(root, 40, 2);
//     // root = insert(root, 50, 5);
//     // root = insert(root, 25, 9);
//     start = clock();
//     int i;
//     for (i = 0; i < 10000000; i++)
//     {
//         root = insert(root, i, -i);
//     }
//     end = clock();
//     printf("%f",(double)(end-start)/CLOCKS_PER_SEC);
//     /* The constructed AVL Tree would be 
// 			30 
// 		/ \ 
// 		20 40 
// 		/ \	 \ 
// 	10 25 50 
// */
    
//     printf("done\n");
//     //preOrder(root);
//     start = clock();
//     for (i = 0; i < 10000000; i++)
//     {
//         findKey(root, 11);
//     }
//     printf("\n%d\n", findKey(root, 11));
//     end = clock();
//     printf("%f",(double)(end-start)/CLOCKS_PER_SEC);
//     return 0;
// }
