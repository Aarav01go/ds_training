#include<iostream>
#include<stdlib.h>
struct node {
   char info;
   struct node *prev,*next;
}

node *GetNode(){
   node *p;
   p=(node*)malloc(sizeof(struct node));
   return p;
}
void insertleft(node *left, node *right,char x){
   node *p;
   p=GetNode();
   p->info=x;
   p->next=left;
   if(left!=NULL) left->prev=prev;
   else right = p;
   left=p;
   
}
void traverse (node *s){
   node *tmp;
   tmp=s;
   while (tmp!=NULL){
      cout<<tmp->info;
      tmp=tmp->next
   }
}
int main(){
 
}
