#include <bits\stdc++.h>
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

Node* DELETEmiddleofLLBRUTE(Node* head){
    Node* temp=head;

    if(temp ==NULL || temp->next ==NULL ){
        return NULL;
    }
    int cnt=0;
    while(temp !=NULL){
        cnt++;
        temp=temp->next;
    }

    int res=cnt/2;
    temp=head;

    while(temp !=NULL){
        res--;
        if(res==0){
        Node* middleNode=temp->next;
        temp->next=temp->next->next;
        delete(middleNode);
        break;
        }
        temp=temp->next;
    }
    return head;
}


Node* DELETEmiddleofLLOPTIMAL(Node* head){
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* middleNode=slow->next;
    slow->next=slow->next->next;
    delete (middleNode);
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=arraytoLL(arr);
    //Node* ansI=DELETEmiddleofLLBRUTE(head);
    Node* ansII=DELETEmiddleofLLOPTIMAL(head);
    cout<<"the LL is ";
    //outputNode(ansI);
    outputNode(ansII);
    return 0;
}
