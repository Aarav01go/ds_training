#include<iostream>
using namespace std;
int power(int a, int n){
   if(n==0) return 1;
   else {
      int x = power(a,n/2);
      if(n%2==0) return x*x;
      else return a*x*x;
   }
}
int main(){
   int a ,n;
   cin>>a>>n;
   cout<<power(a,n);
}