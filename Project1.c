#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int N, Edges;
int Count = 0;

typedef struct Node
{
    int ID;
    struct Node *next;
} Node;

Node *a;

struct Node_Tree *root;

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
    for (int i = 0; i < 10; i++)
    //for (int i = 0; i < Edges; i++)
    {
        printf("done\n");
        fscanf(fin, "%d%d", &goc, &ke);
        if (findKey(root, goc) == -1)
        {
            printf("done\n");
            root = insert(root, goc, Count);
            printf("done\n");
            (a+Count)->ID = goc;
            addNode(ke, (a + Count));
            Count++;
            printf("done\n");
            if (findKey(root,ke) == -1)
            {
                root = insert(root, ke, Count);
                (a+Count)->ID = ke;
                Count++;
            }
        }
        else
        {
            int vt = findKey(root,goc);
            addNode(ke, (a + vt));
            if (findKey(root,ke) == -1)
            {
                root = insert(root, ke, Count);
                (a+Count)->ID = ke;
                Count++;
            }
        }
    }
    return;
}

int main()
{
    FILE *fin;
    fin = fopen("C:\\Users\\sonso\\OneDrive\\Desktop\\Project1\\CauTruc\\roadNet-PA.txt", "r"); //doc file
    if (fin != NULL)
    {
        
        readFile(fin);
        a = (Node *)malloc((N) * sizeof(Node));
        saveStruct(fin);
        fclose(fin);
        printStruct();
        printf("done");
    }
    else
    {
        printf("Khong doc duoc file");
        return 0;
    }
}