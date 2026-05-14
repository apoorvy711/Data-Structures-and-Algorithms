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
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

Node* deletealloccurofKEY(Node* head,int k){
    Node* temp=head;
    while(temp != NULL){
        if(temp->data==k){
            if(temp==head){
                head=temp->next;
            }
            Node* nextNode=temp->next;
            Node* prevNode=temp->prev;
            if(nextNode !=NULL) nextNode->prev=prevNode;
            if(prevNode !=NULL) prevNode->next=nextNode;
            delete(temp);
            temp=nextNode;
        }
        else{
            temp=temp->next; 
        }
    }
    return head;
}

int main(){
    vector<int> arr={10,4,10,10,6,10};
    int k=10;
    Node* head=convertARRtoDLL(arr);
    Node* ans=deletealloccurofKEY(head,k);
    outputNode(ans);
    return 0;
}
