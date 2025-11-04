// implementing algorithm
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
	char info;
	struct Node *Next;
};

struct Node *START;

Node *GetNode() {
	Node *p;
	p=(Node*)malloc(sizeof(struct Node));
	return p;
}
void insBeg(char x) {
	Node *p;
	p=GetNode();
	p->info=x;
	p->Next=START;
	START=p;
}

void Traverse() {
   Node *p;
	p=START;
	while(p!=NULL) {
      cout << p->info<<" ";
		p=p->Next;
	}
   cout<<endl;
}

void reverseLL(){
   Node *p = NULL;
   Node *c = START;
   Node *n ;
   while( c !=NULL){
   n=c->Next;
   c->Next=p;
   p=c;
   c=n;
   }
   START = p;
   Traverse();
}
void inAtEnd(Node *START,char x){
    Node *q;
    q=START;
    Node *p = GetNode();
    p->info=x;
    p->Next=NULL;
    while(q->Next){
        q=q->Next;
    }
    q->Next = p;
}

int delBeg(Node *START){
	Node *p;
	p = START;
	START = START->Next;

}

int size(){
    int count=0;
    Node *q=START;
    while(q){
        count++;
        q=q->Next;
    }
   return count;

}

int main() {
	START=NULL;
	insBeg('A');
	insBeg('B');
	insBeg('C');
	insBeg('D');
	insBeg('E');
	insBeg('F');
   //  inAtEnd(START,'Z');
	Traverse();
    size();
   reverseLL();
   
   

   
}