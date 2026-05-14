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

Node* convertARRtoLL(vector<int> &arr){
    Node*head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

//REVERSE
Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node* newHead= reverseLL(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;
    return newHead;
}

//BRUTE
Node* addONEinLLBRUTE(Node* head){
    head=reverseLL(head);
    Node* temp=head;
    int add=1;
    int carry=0;
    while(temp !=NULL){

        temp->data=temp->data+add;
        if(temp->data < 10){
            carry=0;
            break;
        }
        else {
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1){
        Node* newNode=new Node(carry);
        head=reverseLL(head);
        newNode->next=head;
        return newNode;
    }
    head=reverseLL(head);
    return head;
}

//OPTIMAL
int helper(Node* temp){
    if(temp==NULL) return 1;
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data < 10){
        return 0;
    }
    else{
        temp->data=0;
        return 1;
    }
}

Node* addONEinLLOPTIMAL(Node* head){
    int carry=helper(head);
    if(carry==1){
        Node* newNode= new Node(carry);
        newNode->next=head;
        return newNode;
    }
    return head;
}

int main(){
    vector<int> arr={ 9,9,9,9,9,9};
    Node* head=convertARRtoLL(arr);
    //head=addONEinLLBRUTE(head);
    head=addONEinLLOPTIMAL(head);
    outputNode(head);
    return 0;
}