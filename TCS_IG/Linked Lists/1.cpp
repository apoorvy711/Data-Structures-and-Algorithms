#include<bits\stdc++.h>
using namespace std;

/*
//REVERSE A LL
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val):data(val),next(nullptr),prev(nullptr){}
};

void outputNode(Node* root){
    Node* temp=root;
    while(temp !=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* arrayTOll(vector<int>&arr){
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
    if(head==nullptr || head->next==nullptr) return head;
    Node* newhead=reverseLL(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;
    return newhead;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=arrayTOll(arr);
    head=reverseLL(head);
    outputNode(head);
    return 0;
}

//DETECT A LOOP
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val):data(val),next(nullptr),prev(nullptr){}
};

void outputNode(Node* head){
    Node* temp=head;
    while(temp !=nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

Node* arrayToLL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        temp->next=mover;
        temp=mover;
    }
    return head;
}

bool detectLOOPOPTIMAL(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
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
    bool ansII=detectLOOPOPTIMAL(head);
    if(ansII){
        cout<<"the lopp is present in the LL  ";
    }
    else{
        cout<<"the loop is not present in the LL ";
    }
    return 0;

}

//MIDDLE ELEMENT
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val):data(val),next(nullptr),prev(nullptr){}
};

Node* findMiddle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    Node* middleNode = findMiddle(head);
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}
      
//MERGE TWO SORTED ARRAYS
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

Node* mergetwosortedLL_OPTIMAL(Node* head1, Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    Node* dNode=new Node(-1);
    Node* temp=dNode;
    while(t1 != NULL && t2 !=NULL){
        if(t1->data < t2->data){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        }
        else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
    }
    if(t1) temp->next=t1;
    else temp->next=t2;
    return dNode->next;
}

int main(){
    Node* head1=new Node(2);
    head1->next=new Node(4);
    head1->next->next=new Node(8);
    head1->next->next->next=new Node(10);

    Node* head2=new Node(1);
    head2->next=new Node(3);
    head2->next->next=new Node(3);
    head2->next->next->next=new Node(6);
    head2->next->next->next->next=new Node(11);
    head2->next->next->next->next->next=new Node(14);
    Node* headII=mergetwosortedLL_OPTIMAL(head1,head2);
    outputNode(headII);
    return 0;

}
*/



