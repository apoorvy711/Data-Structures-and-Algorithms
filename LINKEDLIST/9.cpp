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
Node* reverseLLbrute(Node* head){
    Node* temp=head;
    stack<int> st;
    while(temp !=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp !=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

//OPTIMAL
//ITERATIVE APPROACH
Node* reverseLLoptimalITERATIVE(Node* head){
    Node* temp=head;
    Node*prev=NULL;
    while(temp !=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

//RECURSIVE APPROACH
Node* reverseLLoptimalRECURSIVE(Node* head){
    if(head==NULL ||  head->next==NULL){
        return head;
    }

    Node* newHead=reverseLLoptimalRECURSIVE(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;

    return newHead;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=arraytoLL(arr);
    //head=reverseLLbrute(head);
    //head= reverseLLoptimalITERATIVE(head);
    head=reverseLLoptimalRECURSIVE(head);
    outputNode(head);
    return 0;

}