#include <stdio.h>
#include <stdlib.h>

int N, Edges;
int Count = 0;
//tree
typedef struct NodeTree
{
    int key;
    int value;
    struct NodeTree *left;
    struct NodeTree *right;
    int check;
} NodeTree;

NodeTree *root;

int hightNode(NodeTree *p)
{
    if (p == NULL)
        return 0;
    int hightleft = hightNode(p->left);
    int hightright = hightNode(p->right);
    return hightleft > hightright ? (hightleft + 1) : (hightright + 1);
}

void QuayLeft(NodeTree *p)
{
    NodeTree *q;
    if (p != NULL)
    {
        if (p->right != NULL)
        {
            q = p->right;
            p->right = q->left;
            q->left = p;
            p = q;
        }
    }
    return;
}
void QuayRight(NodeTree *p)
{
    NodeTree *q;
    if (p != NULL)
    {
        if (p->left != NULL)
        {
            q = p->left;
            p->left = q->right;
            q->right = p;
            p = q;
        }
    }
    return;
}
void RightBalance(NodeTree *p)
{
    NodeTree *q;
    NodeTree *r;
    q = p->right;
    if (q->check == 1)
    {
        p->check = 0;
        q->check = 0;
        QuayLeft(p);
    }
    else if (q->check == -1)
    {
        r = q->left;
        if (r->check == 0)
        {
            p->check = 0;
            q->check = 0;
        }
        else if (r->check == -1)
        {
            p->check = 0;
            q->check = 1;
        }
        else if (r->check == 1)
        {
            p->check = -1;
            q->check = 0;
        }
        r->check = 0;
        QuayRight(q);
        p->right = q;
        QuayLeft(p);
    }
    return;
}

void LeftBalance(NodeTree *p)
{
    NodeTree *q;
    NodeTree *r;
    q = p->left;
    if (q->check == -1)
    {
        p->check = 0;
        q->check = 0;
        QuayRight(p);
    }
    else if (q->check == 1)
    {
        r = q->right;
        if (r->check == 0)
        {
            p->check = 0;
            q->check = 0;
        }
        else if (r->check == 1)
        {
            p->check = 0;
            q->check = -1;
        }
        else if (r->check == -1)
        {
            p->check = 1;
            q->check = 0;
        }
        r->check = 0;
        QuayLeft(q);
        p->left = q;
        QuayRight(p);
    }
    return;
}

void QuayLeftRight(NodeTree *p)
{
    QuayLeft(p->left);
    QuayRight(p);
    return;
}

void initTree()
{
    root->key = N / 2;
    root->value = N;
    root->left = NULL;
    root->right = NULL;
    root->check = 0;
}

// void addNodeTree(int key, int value)
// {
//     NodeTree *p = root;
//     NodeTree *q;
//     while (1)
//     {
//         if (key > p->key)
//         {
//             if (p->right != NULL)
//                 p = p->right;
//             else
//             {
//                 q = (NodeTree *)malloc(sizeof(NodeTree));
//                 q->key = key;
//                 q->value = value;
//                 p->right = q;
//                 break;
//             }
//         }
//         else if (key < p->key)
//         {
//             if (p->left != NULL)
//                 p = p->left;
//             else
//             {
//                 q = (NodeTree *)malloc(sizeof(NodeTree));
//                 q->key = key;
//                 q->value = value;
//                 p->left = q;
//                 break;
//             }
//         }
//         else
//         {
//             return;
//         }
//     }

//     return;
// }

void addNodeTree(NodeTree *Root, int key, int taller)
{
    if (Root == NULL)
    {
        Root = (NodeTree *)malloc(sizeof(NodeTree));
        Root->key = key;
        Root->value = Count;
        Root->left = NULL;
        Root->right = NULL;
        Root->check = 0;
        taller = 1;
    }
    else if (key < Root->key)
    {
        addNodeTree(Root->left, key, taller);
        if (taller == 1)
        {
            if (Root->check == -1)
            {
                LeftBalance(Root);
                taller = 0;
            }
            else if (Root->check == 0)
            {
                Root->check = -1;
                taller = 1;
            }
            else if (Root->check == 1)
            {
                Root->check = 0;
                taller = 0;
            }
        }
    }
    else if (key > Root->key)
    {
        addNodeTree(Root->right, key, taller);
        if (taller == 1)
        {
            if (Root->check == -1)
            {
                Root->check = 0;
                taller = 0;
            }
            else if (Root->check == 0)
            {
                Root->check = 1;
                taller = 1;
            }
            else if (Root->check == 1)
            {
                RightBalance(Root);
                taller = 0;
            }
        }
    }
    else
    {
        taller = 0;
    }
    return;
}

int findKey(int key)
{
    NodeTree *p = root;
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
}

//tree
typedef struct Node
{
    int ID;
    struct Node *next;
} Node;

Node *a;

Node *initNode()
{
    Node *q = (Node *)malloc(sizeof(Node));
    q->next = NULL;
    return q;
}

void addNode(int k, Node *p)
{
    Node *q = initNode();
    Node *h;
    h = p;
    while (h->next != NULL)
    {
        h = h->next;
    }
    h->next = q;
    q->ID = k;
}

void printStruct()
{
    //for (int i = 0; i < N; i++)
    for (int i = 0; i < 10; i++)
    {
        Node *f = a + i;
        do
        {
            printf("%d ", f->ID);
            f = f->next;
        } while (f != NULL);
        printf("\n");
    }
}

void readFile(FILE *fin)
{
    //tach lay so node va so canh
    char str[5][255];
    for (int i = 0; i < 2; i++)
    {
        fgets(str[0], 255, fin);
    }
    for (int i = 0; i < 5; i++)
    {
        fscanf(fin, "%s", str[i]);
    }
    N = atoi(str[2]);     // so node
    Edges = atoi(str[4]); //so canh
    fgets(str[0], 255, fin);
    fgets(str[0], 255, fin);
}

void saveStruct(FILE *fin)
{
    int goc, ke;
    //for (int i = 0; i < 50; i++)
    for (int i = 0; i < Edges; i++)
    {
        fscanf(fin, "%d%d", &goc, &ke);
        if (findKey(goc) == -1)
        {
            addNodeTree(root, goc, 0);
            addNode(goc, (a + Count));
            addNode(ke, (a + Count));
            Count++;
            if (findKey(ke) == -1)
            {
                addNodeTree(root, ke, 0);
                addNode(goc, (a + Count));
                Count++;
            }
        }
        else
        {
            int vt = findKey(goc);
            addNode(ke, (a + vt));
            if (findKey(ke) == -1)
            {
                addNodeTree(root, ke, 0);
                addNode(goc, (a + Count));
                Count++;
            }
        }
    }
    return;
}

int main()
{
    FILE *fin;
    fin = fopen("D:\\ThucHanh\\Project1\\CauTruc\\roadNet-PA.txt", "r"); //doc file
    if (fin != NULL)
    {
        readFile(fin);
        a = (Node *)malloc((N + 1) * sizeof(Node));
        //root = (NodeTree *)malloc(sizeof(NodeTree));
        //initTree();
        saveStruct(fin);
        fclose(fin);
        printStruct();
    }
    else
    {
        printf("Khong doc duoc file");
        return 0;
    }
}