#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int main(){
   //last me jo number h that is the value initialised(3,x)-to x hai
   vector<int>v3(3,3);
   vector<int>v2(3,2);
   vector<int>v1(3,1);
   vector<vector<int>>vv;
   vv.push_back(v1);
   vv.push_back(v2);
   vv.push_back(v3);
   for(int i=0;i<vv.size();i++){
      for(int j=0;j<vv[i].size();j++){
         cout<<vv[i][j]<<"\t";
      }
      cout<<"\n";
   }
   
}