#include <stdio.h>
#include <stdlib.h>

int N, Edges;
typedef struct NodeKe
{
    int id;
    struct NodeKe *next;
   // struct Node *listNodeKe;
} NodeKe;

typedef struct Node
{
    int ID;
    NodeKe *listNodeKe;
    struct Node *next;
} Node;

Node * khoiTaoNode(){
    Node *q = (Node *)malloc(sizeof(Node));
    q->next = NULL;
    q->listNodeKe = NULL;
    return q;
}

NodeKe * khoiTaoNodeKe(){
    NodeKe *q = (NodeKe *)malloc(sizeof(NodeKe));
    q->next = NULL;
    return q;
}

void addNodeKe(int k, NodeKe *p)
{
    NodeKe *q = khoiTaoNodeKe();
    NodeKe *h;
    h = p;
    while (h->next != NULL)
    {
        h = h->next;
    }
    h->next = q;
    q->id = k;
}
void addNode(int j, Node *cp)
{
    Node *q = khoiTaoNode();
    cp->next = q;
    q->ID = j;
}
void printNodeKe(Node *cp)
{
    printf("%d ", cp->ID);
    NodeKe *h = cp->listNodeKe;
    do
    {
        printf("%d ", h->id);
        h = h->next;
    } while (h != NULL);
    printf("\n");
}

void readFile(FILE *fin, Node *first)
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
    Node *cp;
    cp = first;
    fscanf(fin, "%d", &(cp->ID));
    NodeKe *p = khoiTaoNodeKe();
    cp->listNodeKe = p;
    fscanf(fin, "%d", &(p->id));
    for (int i = 1; i < 11; i++)
    //for (int i = 1; i < Edges; i++)
    {
        int j, k;
        fscanf(fin, "%d%d", &j, &k);
        if (j == cp->ID)
        {
            addNodeKe(k, cp->listNodeKe);
        }
        else
        {
            addNode(j, cp);
            cp = cp->next;
            NodeKe *q = khoiTaoNodeKe();
            cp->listNodeKe = q;
            q->id = k;
        }
    }

    Node *h;
    h = first;
    do{
        printNodeKe(h);
        h = h->next;
    } while (h != NULL);
}

int main()
{
    FILE *fin;
   fin = fopen("D:\\ThucHanh\\Project1\\CauTruc\\RoadNet-CA.txt", "r"); //doc file
    if (fin != NULL)
    {
        Node *first = khoiTaoNode();//tao node goc
        readFile(fin, first);
        fclose(fin);
    }
    else
    {
        printf("Khong doc duoc file");
        return 0;
    }
}