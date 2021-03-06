#include <stdio.h>
#include <stdlib.h>

int N, Edges;

typedef struct Node
{
    int ID;
    int data;
    struct Node *next;
} Node;

Node *a;

Node *initNode()
{
    Node *q = (Node *)malloc(sizeof(Node));
    q->next = NULL;
    return q;
}

void addNode(int k, Node *p, int vt)
{
    Node *q = initNode();
    Node *h;
    h = p;
    while (h->next != NULL)
    {
        h = h->next;
    }
    h->next = q;
    q->data = k;
    q->ID = vt;
}

void printStruct(Node *a)
{
    //for (int i = 0; i < N; i++)
    for (int i = 0; i < 50; i++)
    {
        Node *f = a + i;
        do
        {
            printf("%d ", f->data);
            //printf("%d ", f->ID);
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
    int vt = 0;
    a[0].data = 0;
    a[0].ID = 0;
    for (int i = 0; i < 50; i++)
    // for (int i = 0; i < Edges; i++)
    {
        int goc, ke;
        fscanf(fin, "%d%d", &goc, &ke);
        if (goc == (a + vt)->data)
        {
            addNode(ke, (a + vt), vt+1);
            //vt++;
        }
        else
        {
            vt++;
            (a + vt)->ID = vt;
            (a + vt)->data = goc;
            vt++;
            addNode(ke, (a + vt), vt);
        }
    }
}

int main()
{
    FILE *fin;
    fin = fopen("D:\\ThucHanh\\Project1\\CauTruc\\roadNet-PA.txt", "r"); //doc file
    if (fin != NULL)
    {
        readFile(fin);
        a = (Node *)malloc(N * sizeof(Node));
        saveStruct(fin);
        fclose(fin);
        printStruct(a);
    }
    else
    {
        printf("Khong doc duoc file");
        return 0;
    }
}