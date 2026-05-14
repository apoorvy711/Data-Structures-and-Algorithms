#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

void outputting(Node* head){
    while(head !=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

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

//DELETION in LL

// HEAD
Node* deleteHEAD(Node* head){
    if(head==NULL) return head;
    Node* temp= head;
    head= head->next;
    delete(temp);
    return head;
}

//TAIL
Node* deleteTAIL(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node* temp=head;

    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next ;
    temp->next=nullptr;
    return head;
}

//Kth element
Node* deleteKthElement(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    int cnt=0;
    Node* prev=NULL;
    Node* temp=head;
    while(temp !=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

//VALUE
Node* deleteElement(Node* head,int el){  
    if(head==NULL) return head;

    if(head->data==el){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }

    Node* prev=NULL;
    Node* temp=head;
    while(temp !=NULL){
        if(temp->data==el){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}


//INSERTION IN LL

//HEAD
Node* insert_head(Node* head,int val){
    Node* temp= new Node(val,head);
    return temp;
}

//TAIL
Node* insert_tail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }

    Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}

//ELEMENT VAL AT Kth POSITION
Node* ELEMENTatKthPosition(Node* head,int el,int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(el,head);
    }
    int cnt=0;
    Node*temp=head;
    while(temp !=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x=new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//INSERT AN ELEMENT BEFORE THE VALUE(given)
Node* insert_before_VALUE(Node* head, int el, int val){

    if(head==NULL) return NULL;
    
    if(head->data==val){
        return new Node(el,head);
    }

    Node* temp=head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x= new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={12,5,8,7};
    Node* head=convertARRtoLL(arr);
    //head=deleteHEAD(head);
    // outputting(head);
    //cout<<endl;

    //head=deleteTAIL(head);
    //outputting(head);
    //cout<<endl;

    //head=deleteKthElement(head,3);
    //outputting(head);

    //head=deleteElement(head,7);
    //outputting(head);

    //head=insert_head(head,100);
    //outputting(head);

    //head=insert_tail(head,100);
    //outputting(head);

    //head=ELEMENTatKthPosition(head,11,4);
    //outputting(head);

    head=insert_before_VALUE(head,100, 12);
    outputting(head);

    return 0;
}

