#include<bits/stdc++.h>
using namespace std ;
struct stk {
   int item[100];
   int top=-1;
};
struct stk s;

bool isEmpty(){
   return (s.top==-1);
};
void push(int x){
   if( s.top==99){
      cout<<"stack overflows"<<endl;
      return;
   }
   s.top++;
   s.item[s.top]=x;

};
int pop(){
   if(s.top==-1){
      cout<<"stack underflow"<<endl;
      exit(1);
   }
   int x = s.item[s.top];
   s.top--;
   return x;
};
int stacktop(){
   return s.item[s.top];
};
int main(){
   initialised();
   push(200);
   push(400);
   push(600);
   cout<<pop()<<endl;
   cout<<pop()<<endl;
   cout<<pop()<<endl;
   cout<<pop()<<endl;
}
