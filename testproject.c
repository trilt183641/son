#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int N, Edges;
int Check[1005];
Queue *Q;
//-----------------------------------------------------------------------------------------
//CAU TRUC DS KE

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

Node *khoiTaoNode()
{
    Node *q = (Node *)malloc(sizeof(Node));
    q->next = NULL;
    q->listNodeKe = NULL;
    return q;
}

NodeKe *khoiTaoNodeKe()
{
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
    for (int i = 1; i < 50; i++)
    //for (int i = 1; i <= Edges; i++)
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
    do
    {
        printNodeKe(h);
        h = h->next;
    } while (h != NULL);
}
//----------------------------------------------------------------------------------------

//DUYET THEO CHIEU RONG BFS
int BFS(Node *first, int id)
{
    if (first->ID == id)
    {
        return first->ID;
    }
    push(Q, first->ID);
    Check[first->ID] = 1;
    NodeKe *p = first->listNodeKe;
    int isEmpty = Isempty(Q);
    while (isEmpty != 1)
    {
        int Id = pop(Q);
        if (Id == id)
            return Id;
        Check[Id] = 1;
        do
        {
            if (Check[p->id] == 0)
            {
                push(Q, p->id);
                if (p->id = id)
                    return p->id;
                Check[p->id] = 1;
            }
            p = p->next;
        }while (p->next == NULL);
    }
    return 0;
}

int main()
{
    FILE *fin;
    fin = fopen("D:\\ThucHanh\\Project1\\CauTruc\\email.txt", "r"); //CON TRO file
    if (fin != NULL)
    {
        Node *first = khoiTaoNode(); //tao node goc
        readFile(fin, first);
        fclose(fin);

        // DUYET BFS
        Q = InitQueue();
        for (int i = 1; i <= N; i++)
            Check[i] = 0;
        int a = -6 ;
        int IDNode = 0;
        printf("Nhap vao ID cua Node can tim: ");
        scanf("%d", &IDNode);
        //NodeKe *p = first->listNodeKe;
        //printf("%d\n", p->id);
        do
        {
            printf("goc  %d\n", first->ID);
            if (Check[first->listNodeKe->id] == 0)
            {
                while (first->ID != first->listNodeKe->id)
                {
                    first = first->next;
                    printf("%d...", first->ID);
                }
                printf("\n");
                a = BFS(first, IDNode);
            }
            first->listNodeKe = first->listNodeKe->next;
        }while (first->listNodeKe->next == NULL);
        //if(a != 0 )
        printf("den day chua");
        printf("duyet chua: %d ", a);
        //--------------------------------------------------
    }
    else
    {
        printf("Khong doc duoc file");
        return 0;
    }
}