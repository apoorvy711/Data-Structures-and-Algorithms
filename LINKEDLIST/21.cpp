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

Node* reverseLL(Node* head){
    if(head ==NULL || head->next ==NULL){
        return head;
    }
    Node* newHead=reverseLL(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

Node* findKthNode(Node* temp,int k){
    k--;
    while(temp !=NULL && k > 0){
        k--;
        temp=temp->next;
    }
    return temp;
}

Node* reverse_LL_by_group_size_K(Node* head,int k){
    Node* temp=head;
    Node* prevNode=NULL;
    
    while(temp !=NULL){
        Node* KthNode=findKthNode(temp,k);

        if(KthNode==NULL){
            if(prevNode) prevNode->next=temp;
            break;
        }
        
        Node* nextNode=KthNode->next;
        KthNode->next=NULL;

        reverseLL(temp);

        if(temp==head){
            head=KthNode;
        }
        else{
            prevNode->next=KthNode;
        }

        prevNode=temp;
        temp=nextNode;
        
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    Node* head=convertARRtoLL(arr);
    int k=3;
    Node* ans=reverse_LL_by_group_size_K(head,k);
    outputNode(ans);
    return 0;
}

