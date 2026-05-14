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

//BRUTE
int LENGTHofLLBRUTE(Node* head){
    int cnt=0;
    unordered_map<Node*,int>mpp;
    Node* temp=head;
    while(temp !=NULL){
        if(mpp.find(temp) != mpp.end()){
            int value=mpp[temp];
            return cnt-value;
        }
        mpp[temp]=cnt;
        cnt++;
        temp=temp->next;
    }
    return 0;
}

//OPTIMAL
int lengthoffLL(Node* slow,Node* fast){
    int cnt=1;
    fast=fast->next;
    while(slow != fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int LENGTHofLLOPTIMAL(Node* head){
        Node* slow=head;
    Node* fast=head;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return lengthoffLL(slow,fast);
    }
    return false;
}

int main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* fourth=new Node(4);
    Node* fifth=new Node(5);
    Node* sixth=new Node(6);
    Node* seventh=new Node(7);
    Node* eight=new Node(8);
    Node* ninth=new Node(9);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=eight;
    eight->next=ninth;
    ninth->next=third;
    //int ansI=LENGTHofLLBRUTE(head);
    //cout<<"the length of the LL is "<<ansI<<endl;
    int ansII=LENGTHofLLOPTIMAL(head);
    cout<<"the length of the LL is "<<ansII<<endl;
    return 0;
}

