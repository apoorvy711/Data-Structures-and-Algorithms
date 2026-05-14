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

//BRUTE
Node* intersectionNodeBRUTE(Node* head1,Node* head2){
    map<Node*,int> mpp;
    Node* temp=head1;
    while(temp !=NULL){
        mpp[temp]=1;
        temp=temp->next;
    }
    temp=head2;
    while(temp !=NULL){
        if(mpp.find(temp) !=mpp.end()){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

//BETTER
Node* collisionPoint(Node* temp1,Node* temp2,int d){
    while(d){
        d--;
        temp2=temp2->next;
    }
    while(temp1 != temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;
}

Node* intersectionNodeBETTER(Node* head1,Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    int N1=0;
    int N2=0;
    while(t1 !=NULL){
        N1++;
        t1=t1->next;
    }
    while(t2 !=NULL){
        N2++;
        t2=t2->next;
    }

    if(N1<N2){
        return collisionPoint(head1,head2,N2-N1);
    }
    else{
        return collisionPoint(head2,head1,N1-N2);
    }
}

//OPTIMAL
Node* intersectionNodeOPTIMAL(Node* head1,Node* head2){
    if(head1 ==NULL || head2 ==NULL) return NULL;
    Node* t1=head1;
    Node* t2=head2;
    while(t1 != t2){
       if (t1 == nullptr) {
        t1 = head2;   // If t1 finished list1, start from head2
    } else {
        t1 = t1->next;  // Otherwise, move to next node
    }

    if (t2 == nullptr) {
        t2 = head1;   // If t2 finished list2, start from head1
    } else {
        t2 = t2->next;  // Otherwise, move to next node
    }
    }
    return t1;
}

int main(){
    Node* common=new Node(4);
    common->next=new Node(6);
    common->next->next=new Node(2);

    Node* head1=new Node(3);
    head1->next=new Node(1);
    head1->next->next=common;
    

    Node* head2=new Node(1);
    head2->next=new Node(2);
    head2->next->next=new Node(4);
    head2->next->next->next=new Node(5);
    head2->next->next->next->next=common;

    cout<<"the list 1 is "<<" ";
    outputNode(head1);
    cout<<endl;

    cout<<"the list 2 is "<<" ";
    outputNode(head2);
    cout<<endl;

    Node*ansI=intersectionNodeBRUTE(head1,head2);
    if(ansI !=NULL){
        cout << "Intersection at node with value: " << ansI->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    Node*ansII=intersectionNodeBETTER(head1,head2);
    if(ansII !=NULL){
        cout << "Intersection at node with value: " << ansII->data << endl;
     } else {
        cout << "No intersection found." << endl;
    }

    Node*ansIII=intersectionNodeOPTIMAL(head1,head2);
    if(ansIII !=NULL){
        cout << "Intersection at node with value: " << ansIII->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    return 0;
}