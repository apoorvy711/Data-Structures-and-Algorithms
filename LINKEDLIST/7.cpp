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
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
 
Node* sort_zero_ones_twos(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);
    Node* zero=zeroHead;
    Node* one=oneHead;
    Node* two=twoHead;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=(oneHead->next)?(oneHead->next):(twoHead->next);
    one->next=twoHead->next;
    two->next=NULL;

    Node*newHead=zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

int main(){
    vector<int> arr={1,0,1,2,0,2,1};

    Node* head=convertARRtoLL(arr);
    head=sort_zero_ones_twos(head);
    outputNode(head);
    cout<<endl;
    return 0;
}