#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;

    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
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








//DELETE HEAD IN DLL
Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* prev=head;
    head=head->next;

    head->back=nullptr;
    prev->next=nullptr;

    delete prev;
    return head;
}

//DELETE TAIL IN DLL
Node*deleteTAIL(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node* tail=head;
    while(tail->next !=NULL){
        tail=tail->next;
    }

    Node* prev=tail->back;
    prev->next=nullptr;
    tail->back=nullptr;

    delete tail;
    return head;
} 

//DELETE THE Kth ELEMENT IN DLL
Node* RemoveKthElement(Node* head,int k){
    if(head==nullptr){
        return nullptr;
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }

    Node* prev= temp->back;
    Node* front=temp->next;

    if(prev==NULL && front==NULL){
        return NULL; 
    }
    else if(prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        deleteTAIL(head);
    }

    prev->next=front;
    front->back=prev;

    temp->next=nullptr;
    temp->back=nullptr;
     
    delete temp;
    return head;
}

// Delete a node from DLL
void deleteNode(Node* temp) {
    if (temp == nullptr) return;

    Node* prev = temp->back;
    Node* front = temp->next;

    if (front == nullptr) { // if it's the last node
        if (prev) prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    if (prev) prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
}

// Remove the k-th node from DLL
Node* deleteKthNode(Node* head, int k) {
    if (head == nullptr) return head;

    Node* temp = head;
    int cnt = 1;

    while (temp != nullptr) {
        if (cnt == k) {
            if (temp == head) {
                head = head->next;
                if (head != nullptr) head->back = nullptr;
                delete temp;
                return head;
            } else {
                deleteNode(temp);
                return head;
            }
        }
        temp = temp->next;
        cnt++;
    }
    return head; // If k > size of list, return original head
}

//INSERTION
//INSERT BEFORE THE HEAD IN DLL
Node*insertbeforeHead(Node* head,int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}

//INSERT BEFORE THE TAIL IN DLL
Node* insertbeforeTAIL(Node* head,int val){
    if(head->next==NULL){
        return insertbeforeHead(head,val);
    }
    Node* tail=head;
    while(tail->next !=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newNode=new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;

    return head;
}

//INSERT BEFORE THE Kth ELEMENT IN DLL
Node* insertbeforeKthELEMENT(Node* head,int k,int val){
    if(k==NULL){
        return insertbeforeHead(head,val); 
    }
    Node* temp=head;
    int cnt=0;
    while(temp !=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}

//INSERT BEFORE THE NODE IN DLL
void insertbeforetheNODE(Node* node,int val){
    Node* prev=node->back;
    Node* newNode= new Node(val,node,prev);
    prev->next=newNode;
    node->back=newNode;
}

int main(){
    vector<int> arr={12,5,8,7};
    Node* head=convertarrtoDDL(arr);
    cout<<endl;
    //head=deleteHead(head);
    cout<<endl;
    //deleteTAIL(head);
    //head=RemoveKthElement(head,3);
    //head=deleteKthNode(head,3);
    //head=insertbeforeHead(head,100);
    //head=insertbeforeTAIL(head,100);
    //head=insertbeforeKthELEMENT(head,2,100);
    insertbeforetheNODE(head->next->next,100);
    outputting(head);
    return 0;
}