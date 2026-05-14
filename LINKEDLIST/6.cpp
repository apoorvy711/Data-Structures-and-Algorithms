#include<bits/stdc++.h>
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

Node* seggregateODDandEVEN(Node* head){
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=head->next;

    while(even !=NULL && even->next !=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }

    odd->next=evenHead;
    return head;
}

int main(){
    vector<int> arr={1,2,3,4 };
    Node* head=convertARRtoLL(arr);
    seggregateODDandEVEN(head);
    outputNode(head);
    cout<<endl;
    return 0;
}
