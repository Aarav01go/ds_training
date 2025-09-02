#include <bits/stdc++.h>
using namespace std;
int main() {
   vector<int>v3(3,3);
   vector<int>v2(3,2);
   vector<int>v1(3,1);
   vector<vector<int>>vv;
   vv.push_back(v1);
   vv.push_back(v2);
   vv.push_back(v3);
   for(int i=2;i>=0;i--){
      for(int j=0;j<vv[i].size();j++){
         cout<<vv[i][j]<<"\t";
      }
      cout<<"\n";
   }

}