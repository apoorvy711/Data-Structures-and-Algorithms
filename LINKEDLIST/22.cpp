#include<bits\stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

void outputNode(Node* head){
    Node* temp=head;
    while(temp !=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<endl;
}

Node* arraytoLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

Node* KthNode(Node* temp,int k ){
    int cnt=0;
    while(temp !=NULL){
        if(cnt==k) return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
}

Node* rotateLL(Node* head,int k){
    if(head== NULL || head->next==NULL) return NULL;
    int len=0;
    Node* tail=head;
    while(tail->next !=NULL){
        len++;
        tail=tail->next;
    }
    if(k % len==0) return head;
    k=k%len;
    tail->next=head;
    Node* newLastNode=KthNode(head,len-k);
    head=newLastNode->next;
    newLastNode->next=NULL;
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=arraytoLL(arr);
    int k=2;
    Node* ans=rotateLL(head,k);
    outputNode(ans);
    return 0;
}

