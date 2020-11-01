#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

int N, Edges;
int Count = 0;
int demnodeduyetBFS = 0;
int demnodeduyetDFS = 0;
int soLienThong = 0;

typedef struct Node
{
    int ID;
    struct Node *next;
} Node;

Node *a;
struct Node_Tree *root;

int *check;

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
    int i;
    for (i = 0; i < 1000; i++)
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
    int i;
    for (i = 0; i < 2; i++)
    {
        fgets(str[0], 255, fin);
    }
    for (i = 0; i < 5; i++)
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
    int goc, ke, i;
    //for (i = 0; i < 1000; i++)
    for (i = 0; i < Edges; i++)
    {
        fscanf(fin, "%d%d", &goc, &ke);
        if (findValue(root, goc) == -1)
        {
            root = insert(root, goc, Count);
            (a + Count)->ID = goc;
            addNode(ke, (a + Count));
            Count++;
            if (findValue(root, ke) == -1)
            {
                root = insert(root, ke, Count);
                (a + Count)->ID = ke;
                Count++;
            }
        }
        else
        {
            int vt = findValue(root, goc);
            addNode(ke, (a + vt));
            if (findValue(root, ke) == -1)
            {
                root = insert(root, ke, Count);
                (a + Count)->ID = ke;
                Count++;
            }
        }
    }
    return;
}

void resetCheck()
{
    for (int i = 0; i < N; i++)
    {
        *(check + i) = 0;
    }
    return;
}

Node *BFS(int start, int ID)
{
    if (findValue(root, start) == -1)
    {
        printf("Khong ton tai node bat dau %d", start);
        return NULL;
    }
    else if (findValue(root, ID) == -1)
    {
        printf("Khong ton tai node can tim %d", ID);
        return NULL;
    }
    else
    {
        pushNodeQueue(start);
        *(check + findValue(root, start)) = 1;
        while (firstNodeQueue != NULL)
        {
            int first = popNodeQueue();
            if(first == -1){
                printf("Khong ton tai duong di tu %d den %d\n",start, ID);
                resetCheck();
                freeQueue();
                return NULL;
            }
            demnodeduyetBFS++;
            int vt = findValue(root, first);
            if (first == ID)
            {
                resetCheck();
                freeQueue();
                return (a + vt);
            }
            else
            {
                Node *p = (a + vt)->next;
                while (p != NULL)
                {
                    int vtKe = findValue(root, p->ID);
                    if (*(check + vtKe) == 0)
                    {
                        pushNodeQueue(p->ID);
                        *(check + vtKe) = 1;
                    }
                    p = p->next;
                }
            }
        }
    }
}

void pushQ(Node *p)
{
    if (p->next != NULL)
    {
        pushQ(p->next);
    }
    int vtKe = findValue(root, p->ID);
    ;
    if (*(check + vtKe) == 0)
    {
        pushfirstNodeQueue(p->ID);
        *(check + vtKe) = 1;
    }
    return;
}

Node *DFS(int start, int ID)
{
    if (findValue(root, start) == -1)
    {
        printf("Khong ton tai node bat dau %d\n", start);
        return NULL;
    }
    else if (findValue(root, ID) == -1)
    {
        printf("Khong ton tai node can tim %d\n", ID);
        return NULL;
    }
    else
    {
        pushNodeQueue(start);
        *(check + findValue(root, start)) = 1;
        while (firstNodeQueue != NULL)
        {
            int first = popNodeQueue();
            if(first == -1){
                printf("Khong ton tai duong di tu %d den %d\n",start, ID);
                resetCheck();
                freeQueue();
                return NULL;
            }
            demnodeduyetDFS++;
            int vt = findValue(root, first);
            if (first == ID)
            {
                resetCheck();
                freeQueue();
                return (a + vt);
            }
            else
            {
                pushQ((a + vt)->next);
            }
        }
    }
}

int soDoThiLienThong()
{
    int vt = 0;
    while(1)
    {
        while (*(check + vt) == 1)
        {
            vt++;
            if(vt == N-1)
                return;
        }

    }
}

int main()
{
    FILE *fin;
    fin = fopen("D:\\Son\\CauTruc\\roadNet-PA.txt", "r"); //doc file
    if (fin != NULL)
    {
        readFile(fin);
        a = (Node *)malloc((N) * sizeof(Node));
        check = (int *)malloc(N * sizeof(int));
        saveStruct(fin);
        fclose(fin);
        //printStruct();

        BFS(0, 6309);
        printf("done\n");
        printf("%d\n", demnodeduyetBFS);
        printf("done\n");
        DFS(0, 5455);
        printf("done\n");
        printf("%d\n", demnodeduyetDFS);
        printf("done\n");
    }
    else
    {
        printf("Khong doc duoc file");
        return 0;
    }
}
