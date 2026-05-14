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
    Node*prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

//BRUTE
vector<pair<int,int>> pairwithSUMBRUTE(Node* head,int sum){
    vector<pair<int,int>> result;
    Node* temp1=head;
    while(temp1 !=NULL){
        Node* temp2=temp1->next;
        while(temp2 !=NULL && (temp1->data + temp2->data <= sum)){
            if(temp1->data+ temp2->data==sum){
                result.push_back({temp1->data,temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return result;
}

//OPTIMAL
Node* tailHead(Node* head){
    Node* temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    return temp;
}

vector<pair<int,int>> pairwithSUMOPTIMAL(Node* head,int sum){
    vector<pair<int,int>> result;
    Node* left=head;
    Node* right=tailHead(head);
    while(left->data < right->data){
        if(left->data + right->data==sum){
            result.push_back({left->data , right->data});
            left=left->next;
            right=right->prev;
        }
        else if(left->data + right->data > sum){
            right=right->prev;
        }
        else {
            left=left->next;
        }
    }
    return result;
}

int main(){
    vector<int> arr={1,2,3,4,9};
    int sum=5;
    Node* head=convertARRtoDLL(arr);
    //vector<pair<int,int>> ansI=pairwithSUMBRUTE(head,sum);
    //cout<<"the pairs with sum =10 are:"<<endl;
    //for(auto it:ansI){
    //    cout<<"("<<it.first<<","<<it.second<<")"<<endl;
    //}
    vector<pair<int,int>> ansII=pairwithSUMOPTIMAL(head,sum);
    cout<<"the pairs with sum =10 are:"<<endl;
    for(auto it:ansII){
        cout<<"("<<it.first<<","<<it.second<<")"<<endl;
    }
    return 0;
}

