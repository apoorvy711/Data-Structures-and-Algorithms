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
Node* mergetwosortedLL_BRUTE(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    vector<int>arr;
    while(temp1 !=NULL){
        arr.push_back(temp1->data);
        temp1=temp1->next;
    }
    while(temp2 !=NULL){
        arr.push_back(temp2->data);
        temp2=temp2->next;
    }
    sort(arr.begin(),arr.end());
    Node* head=arraytoLL(arr);
    return head;
}

//OPTIMAL
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

int main(){
    Node* head1=new Node(2);
    head1->next=new Node(4);
    head1->next->next=new Node(8);
    head1->next->next->next=new Node(10);

    Node* head2=new Node(1);
    head2->next=new Node(3);
    head2->next->next=new Node(3);
    head2->next->next->next=new Node(6);
    head2->next->next->next->next=new Node(11);
    head2->next->next->next->next->next=new Node(14);

    //Node* headI=mergetwosortedLL_BRUTE(head1,head2);
    //outputNode(headI);
    Node* headII=mergetwosortedLL_OPTIMAL(head1,head2);
    outputNode(headII);
    return 0;

}