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
/*
//BRUTE
Node* sortLL_BRUTE(Node* head){
    vector<int>arrr;
    Node* temp=head;
    while(temp !=NULL){
        arrr.push_back(temp->data);
        temp=temp->next;
    }
    sort(arrr.begin(),arrr.end());
    temp=head;
    for(int i=0;i<arrr.size();i++){
        temp->data=arrr[i];
        temp=temp->next;
    }
    return head;
}
*/
//OPTIMAL
Node* findMiddle(Node* head){
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
 
Node* mergetwosortedLL_OPTIMAL(Node* head1,Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    Node* dNode=new Node(-1);
    Node* temp=dNode;

    while(t1 !=NULL && t2 !=NULL){
        if(t1->data < t2->data){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        }
        else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
    }
    if(t1) temp->next=t1;
    else temp->next=t2;
    return dNode->next;
}

Node* sortLL_OPTIMAL(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node* mid=findMiddle(head);
    Node* leftHead=head;
    Node* rightHead=mid->next;
    mid->next=NULL;
    leftHead=sortLL_OPTIMAL(leftHead);
    rightHead=sortLL_OPTIMAL(rightHead);
    return mergetwosortedLL_OPTIMAL(leftHead,rightHead);
}

int main(){
    vector<int> arr={3,4,2,1,5};
    Node* head=arraytoLL(arr);
    //Node* ansI=sortLL_BRUTE(head);
    //outputNode(ansI);
    Node* ansII=sortLL_OPTIMAL(head);
    outputNode(ansII);
    return 0;
}
