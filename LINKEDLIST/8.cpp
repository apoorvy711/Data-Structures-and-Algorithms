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

//BRUTE
Node* RemoveNthfromEndBRUTE(Node* head,int N){
    if(head==NULL){
        return NULL;
    }

    int cnt=0;
    Node* temp=head;
    //COUNTING OF NODES
    while(temp !=NULL){
        cnt++;
        temp=temp->next;
    }
    //CHECK IF HEAD IS N
    if(cnt==N){
        Node* newHead=head->next;
        delete(newHead);
        return head;
    }

    int res=cnt-N;
    temp=head;
    while(temp !=NULL){
        res--;
        if(res==0) break;
        temp=temp->next;
    }

    Node* delNode=temp->next;
    temp->next=temp->next->next;
    delete( delNode);
    return head;
}

//OPTIMAL
Node* RemoveNthfromEndOPTIMAL(Node* head,int N){
    Node* fast=head;
    for(int i=0;i<N;i++){
        fast=fast->next;
    }

    Node* slow=head;
    if(fast==NULL) return head->next;

    while(fast->next !=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node* delNode=slow->next;
    slow->next= slow->next->next;
    delete(delNode);
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    int N=2;
    Node* head=arraytoLL(arr);
    //head=RemoveNthfromEndBRUTE(head,N);
    head=RemoveNthfromEndOPTIMAL(head,N);
    outputNode(head);
    return 0;

}
