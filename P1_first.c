#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int N, Edges;
int n, count = 0;
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
typedef struct map
{
    int id;
    int value;

} map;
map *Map;
Node *a;

void canbangMap(){
    
}

int findIdOfValue_count(int value)
{
    int l = 0;
    int r = n;
    int m = (l+r)/ 2;
    while (Map[m].value != -1)
    {
        if (Map[m].value == value)
            return Map[m].id;
        if (Map[m].value < value)
        {
            l = m;
            m = (l + r) / 2 + 1;
        }
        else
        {
            r = m;
            m = (l + r) / 2 - 1;
        }
    }
    a[count].value = value;
    Map[m].value = value;
    Map[m].id = count;
    count++;
    return -1;
}

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

void printStruct(Node *a)
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
    int vt = 0;
    int i;
    for (i = 0; i < Edges; i++)
    {
        int goc, ke;
        fscanf(fin, "%d%d", &goc, &ke);
    }
}

int main()
{
    FILE *fin;
    fin = fopen("D:\\ThucHanh\\Project1\\CauTruc\\roadNet-PA.txt", "r"); //doc file
    if (fin != NULL)
    {
        readFile(fin);
        while ((int)pow(2, n) - 1 < N)
        {
            n++;
        }
        n = pow(2, n) - 1;
        a = (Node *)malloc(N * sizeof(Node));
        Map = (map *)malloc(n * sizeof(map));
        int i;
        for (i = 0; i < n; i++)
        {
            Map[i].value = -1;
            Map[i].id = -1;
        }
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
