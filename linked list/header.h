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

