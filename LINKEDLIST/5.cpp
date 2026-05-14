#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

void ouputNode(Node* head){
    while(head !=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* convertARRtoLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

Node* ADDTWONUM(  Node* num1,  Node* num2){
    Node* dummyHead=new Node(-1);
    Node* curr=dummyHead;
    Node* temp1=num1;
    Node* temp2=num2;
    int carry=0;
    
    while(temp1 !=nullptr || temp2 !=nullptr){
        int sum=carry;

        if(temp1){
            sum= sum + temp1->data;
        }
        if(temp2){
            sum= sum + temp2->data;
        }

        Node* newNode= new Node(sum %10);
        carry=sum/10;

        curr->next=newNode;
        curr=curr->next;

        if(temp1){
            temp1=temp1->next;
        }
        if(temp2){
            temp2=temp2->next;
        }   
    }
    if(carry){
        Node* newNode=new Node(carry);
        curr->next=newNode;
    }
    return dummyHead->next;
}

int main(){
    vector<int> num1={2, 4, 3};
    vector<int> num2={5, 6, 4};

    Node* L1=convertARRtoLL(num1);
    Node* L2=convertARRtoLL(num2);

    Node* head=ADDTWONUM(L1,L2);
    cout<<"the linked list is : ";

    ouputNode(head);
    return 0;
}