#include<iostream>
#include<vector>
using namespace std;
bool binserach( vector<int>&v, int start, int last , int n){
   if(start>last)return false;
  int  mid = (start +last)/2;
  if (n==v[mid]) return true;
   if(n<v[mid]) return binserach( v, start, mid-1,n);
   else return binserach( v,mid+1, last ,n);
  
}
int main(){
   int start, last, n;
   vector<int>v={1,2,3,4,5,6,7,8,9};
   cin>>n;
   cout << binserach( v,start,last,n);

}