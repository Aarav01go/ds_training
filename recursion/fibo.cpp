#include<iostream>
using namespace std;
int fibo(int n){
   if(n<=2) return n-1;
   return fibo(n-1) + fibo(n-2);
}

int main(){
   int n;
   cout<<"Enter n : ";
   cin>>n;
   // cout<<fibo(n,1,1,0)<<endl;
   cout<<fibo(n)<<endl;
   return 0;
   
}