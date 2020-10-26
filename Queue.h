#include <stdio.h>
#include <stdlib.h>

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

typedef struct NodeQ
{
    Node Data;
    struct NodeQ *Next;
} NodeQ;

typedef struct Queue
{
    NodeQ *Front;
    NodeQ *Rear; //Node dau va Node cuoi
    int count;          //dem so phan tu
} Queue;

Queue* InitQueue()
{
    Queue *Q = (Queue *)malloc(sizeof(Queue)); 
    Q->Front = Q->Rear = NULL;
    Q->count = 0;
    return Q;
}

NodeQ* InitNode(int Data){
    NodeQ *p = (NodeQ*)malloc(sizeof(NodeQ));
    p->Data = Data;
    p->Next = NULL;
    return p; 
}


int Isempty (Queue *Q) 
{
    if (Q->count == 0) 
        return 1;
    return 0;
}

void push(Queue *Q, int x) //them phan tu vao cuoi Queue
{
    NodeQ *p = InitNode(x); 
    if (Isempty(Q))
    {
        Q->Front = Q->Rear = p;
    }
    else 
    { 
        Q->Rear->Data = p->Data;
        Q->Rear = p;
    }
    Q->count ++ ; 
}

int pop(Queue *Q) //Loai bo phan tu khoi dau hang doi
{
    // if (Isempty(Q)) 
    // {
    //     printf("Hang doi rong !");
    //     return 0;
    // }
    // else
    // {
        Node *x = Q->Front->Data;
        Q->Front = Q->Front->Next;
        Q->count --;
        return x; 
    //}
}

int font(Queue *Q){
    int x = Q->Front->Data;
    return x;
}

//Tao CTDL HANg DOI
// typedef struct QueueNode
// {
//     int data;
//     struct QueueNode *Next;
// } QNode;

// typedef struct Queue
// {
//     QNode *head;
//     QNode *tail;
//     int count;
// } Queue;

// Queue *initQueue()
// {
//     Queue *Q = (Queue *)malloc(sizeof(Queue));
//     Q->count = 0;
//     Q->head = NULL;
//     Q->tail = NULL;
//     return Q;
// }

// QNode *InitQNode(){
//     QNode *p = (QNode*)malloc(sizeof(QNode));
//     p->Next = NULL;
//     return p;
// }


// int main(){
//     Queue *Q = InitQueue();
//     printf("%d\n",Isempty(Q));
    
//     push(Q,3);
//     printf("%d\n",Isempty(Q));

    
//     printf("%d\n",pop(Q));
//     printf("%d\n",Isempty(Q));
// }