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

//CONVERT AN ARRAY TO LL
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

//LENGTH OF AN ARRAY
int LENGTHofLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    cout<<"the length of the LL is:";
    return cnt;
}

//SEARCH AN ELEMENT
int searchanelementinLL(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data == val) return 1;
        temp=temp->next;
    }
    return 0;
}
int main(){
    vector<int> arr={12,5,8,7};
    Node* head=convertARRtoLL(arr);

    cout<<head->data; 
    cout<<endl;

    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    cout<<LENGTHofLL(head);
    cout<<endl;

    cout<<searchanelementinLL(head,5);
    cout<<endl;
    
    return 0;
}