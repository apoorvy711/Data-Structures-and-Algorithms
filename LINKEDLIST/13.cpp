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
    Node*head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

//BRUTE
Node* middleELEMENTBRUTE(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp !=NULL){
      cnt++;
      temp=temp->next;
    }
    int midNode=(cnt/2) + 1;
    temp=head;
    while(temp !=NULL){
        midNode=midNode-1;
        if(midNode==0) break;
        temp=temp->next;
    }
    return temp;
}

//OPTIMAL
Node* middleELEMENTOPTIMAL(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast !=NULL && fast->next !=NULL ){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=arraytoLL(arr);
    //Node* ansI=middleELEMENTBRUTE(head);
    Node* ansII=middleELEMENTOPTIMAL(head);
    //cout<<"the middle node of the element is "<<ansI->data<<" ";
    cout<<"the middle node of the element is "<<ansII->data<<" ";
    return 0;

}