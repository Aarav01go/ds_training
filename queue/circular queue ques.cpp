#include<iostream>
#include"headerqueue.h"

using namespace std;

void EnQueue(Node* front , Node* REAR , int x){
   Node* p = GetNode();
   p->info = x;
   p->Next = NULL;
   if (REAR!= NULL) REAR->Next=p;
   else FRONT =p;
   REAR=p;
}
void DeQueue ()

int main(){

}