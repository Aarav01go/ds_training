#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

#include <stdlib.h>


int delBeg(Node *START){
	Node *p;
	p = START;
	START = START->Next;
	int x = p->info;
	return x;
}

int delEnd(Node **q){
	int x = (*q)->Next->info;
	FreeNode((*q)->Next);
	return x;
}

int delAft(Node **q){
	Node *p;
	int x = (*q)->Next->info;
	return x;
}
void FreeNode(Node *x){
    x->Next = NULL;
}



struct Queue {
    char item[10];
    int FRONT;
    int REAR;
};

void initialize(Queue* Q) {
    Q->REAR = -1;
    Q->FRONT = 0;
}

bool IsEmpty(Queue* Q) {
    return (Q->REAR - Q->FRONT + 1 == 0);
}

void EnQueue(Queue* Q, char x) {
    if (Q->REAR == 9) {
        cout << "QUEUE OVERFLOW\n";
        exit(1);
    } else {
        Q->REAR++;
        Q->item[Q->REAR] = x;
    }
}

char DeQueue(Queue* Q) {
    if (IsEmpty(Q)) {
        cout << "QUEUE UNDERFLOW\n";
        exit(1);
    } else {
        char x = Q->item[Q->FRONT];
        Q->FRONT++;
        return x;
    }
}

void Display(Queue* Q) {
    if (IsEmpty(Q)) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = Q->FRONT; i <= Q->REAR; i++) {
        cout << Q->item[i] << " ";
    }
    cout << endl;
}

#endif