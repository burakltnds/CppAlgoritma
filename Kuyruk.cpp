#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* bas;  
    Node* son;  
} Queue;

void initialize(Queue* q) {
    q->bas = NULL;
    q->son = NULL;
}

void enQueue(Queue* q, int value) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = value;
    yeni->next = NULL;

    if (q->son == NULL) { 
        q->bas = yeni;
        q->son = yeni;
        return;
    }
    q->son->next = yeni; 
    q->son = yeni;        
}

void deQueue(Queue* q) {
    if (q->bas == NULL) {  
        printf("Kuyruk Bos\n");
        return;
    }

    Node* temp = q->bas;   
    q->bas = q->bas->next; 

    if (q->bas == NULL) {  
        q->son = NULL;
    }

    free(temp);
}

void printQueue(Queue* q) {
    if (q->bas == NULL) {
        printf("Kuyruk Bos\n");
        return;
    }

    Node* temp = q->bas;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    enQueue(&q, 5);
    enQueue(&q, 3);
    enQueue(&q, 65);
    enQueue(&q, 20);

    printf("Kuyruk: ");
    printQueue(&q);

    deQueue(&q);
    printf("Dequeue Kuyruk: ");
    printQueue(&q);

    return 0;
}
