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

//BRUTE
bool checkifPALINDROMEBrute(Node* head){
    stack<int> st;
    Node* temp=head;
    while(temp !=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp !=NULL){
        if(temp->data != st.top()) return false;
        temp=temp->next;
        st.pop();
    }
    return true;
}

//OPTIMAL
Node* reverseLL(Node* head){
    Node* temp=head;
    Node*prev=NULL;
    while(temp !=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

bool checkifPALINDROMEOptimal(Node* head){
    if (head == nullptr || head->next == nullptr) return true;
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverseLL(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second !=NULL){
        if(first->data != second->data){
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(newHead);
    return true;
}
    
int main(){
    vector<int> arr={1,2,3,2,1};
    Node* head=arraytoLL(arr);
    //bool ansI=checkifPALINDROMEBrute(head);
    //if(ansI){
    //    cout<<"the number is palindrome";
    //}
    //else{
    //    cout<<"the number is not palindrome";
    //}

    bool ansII=checkifPALINDROMEOptimal(head);
    if(ansII){
        cout<<"the number is palindrome";
    }
    else{
        cout<<"the number is not palindrome";
    }
    return 0;
}
