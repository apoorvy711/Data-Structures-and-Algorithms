#include<bits/stdc++.h>
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

//PRINT OUTPUT
void outputting(Node* head){
    while(head !=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//CONVERT ARRAY TO DLL  
Node* convertarrtoDDL( vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

//BRUTE
Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    stack<int> st;
    Node* temp=head;
    while(temp !=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp !=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

//OPTIMAL
Node* reverseaDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* last=NULL;
    Node* current=head;
    while(current !=NULL){
        last=current->prev;
        current->prev=current->next;
        current->next=last;
        current=current->prev;
    }
    return last->prev;

}

int main(){
    vector<int> arr={12,5,8,7};
    Node* head=convertarrtoDDL(arr);
    //head=reverseDLL(head);
    head=reverseaDLL(head);
    outputting(head);
    return 0;
}