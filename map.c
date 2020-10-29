#include <stdio.h>

typedef struct node
{
    int value;
    struct node *left, *right, *parent;

} node;

int height(node *a)
{
    if (a == NULL)
        return 0;
    int c = height(a->left) + 1;
    int d = height(a->right) + 1;
    return c > d ? c : d;
}
int main()
{
    printf("%d", max(3, 4))
}
