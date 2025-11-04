#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
struct Node{
   int  data;
   Node* next;
   Node( int val){
      data = val;
      next= nullptr;
   }


};
int lengthll( Node* head){
   int cnt=0;
   Node* temp =head;
   while(temp){
      temp=temp->next;
      cnt++;
   }
   return cnt;

}
Node* convertarray( vector<int> &v){
   Node* head= new Node(v[0]);
   Node* move= head;
   for(int i=1;i<v.size();i++){
      Node* temp = new Node(v[i]);
      move->next=temp;
      move = temp;
   }
   return head;
}
int searchll(Node* head,int val){
   Node* temp = head;
   while(temp){
      if (temp->data == val) return 1;
      temp=temp->next; 
   }
   return 0;
}
Node* delhead( Node* head){
   if (head == nullptr) return head;
    Node* temp =head;
    head = head->next;
    delete temp;
    return head;
}
Node* deltail(Node* head){
   if(head==nullptr || head->next == nullptr) return nullptr;
   Node* temp=head;
   while(temp->next->next!=nullptr){
      temp=temp->next;
   }
   free (temp->next);
   temp->next= nullptr;
   return head;
}
Node* deletek(Node*head, int k){
   if(head == nullptr) return head;
   if(k==1){
      head=head->next;
      return head;
   }
   Node* temp = head;
   int cnt =0;
   Node* prev= nullptr;
   while( temp!=nullptr){
      cnt++;
      if(cnt+1==k){
         prev=temp->next;
         free(temp->next);
         prev=temp->next->next;
         break;
      }
      temp=temp->next;
   }
   return head;

}
int main(){
   vector<int> arr= {1,2,3,4,5,6};
   Node* head = convertarray(arr);
   cout<<"length is "<<lengthll(head);
   cout << "   is 4 present check : "<< searchll(head,4)<< endl;
   // head = delhead(head);
   // cout << "After deleting head:\n";
   // Node* temp = head;
   // while (temp) {
   //      cout << temp->data << " ";
   //      temp = temp->next;
   //  }
   // cout << "After deleting tail:\n";
   head = deltail(head);
   head = deletek(head,3);
   Node* temp = head;
   while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
      }
  
}
