#include<bits\stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
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

Node* convertARRtoDLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node*prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

Node* deleteDuplicates(Node* head){
    Node* temp=head;
    while(temp !=NULL && temp->next !=NULL){
        Node* nextNode=temp->next;
        while(nextNode !=NULL && nextNode->data==temp->data){
            Node* duplicate=nextNode;
            nextNode=nextNode->next;
            delete(duplicate);
        }
        temp->next=nextNode;
        if(nextNode) nextNode->prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,1,1,2,3,3,4};
    Node* head=convertARRtoDLL(arr);
    Node* ans=deleteDuplicates(head);
    outputNode(ans);
    return 0;
}
