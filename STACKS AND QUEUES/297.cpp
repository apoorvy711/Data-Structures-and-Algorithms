#include<bits/stdc++.h>
using namespace std;

//implement stack using arrays
class Stack{
    int top=-1;
    int st[10];
    public:
    void push(int x){
        if(top>=9){
            cout<<"overflow condition";
            return ;
        }
        top=top+1;
        st[top]=x;
    }
    int peek(){
        if(top==-1){
            cout<<"empty stack";
            return -1;
        }
        return st[top];
    }
    void pop(){
        if(top==-1){
            cout<<"stack empty";
            return ;
        }
        top=top-1;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;
    s.push(40);
    cout << "Top now: " << s.peek() << endl;
    return 0;
}
/*
//Implement queue using arrays
class Queue{
    int size=4;
    int start=-1,end=-1;
    int st[4];
    int curr_size=0;
    public:
    void push(int x){
        if(curr_size==size){
            cout<<"queue overflow";
            return;
        }
        if(curr_size==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%size;
        }
        st[end]=x;
        curr_size++;
    }
    int pop(){
        if(curr_size==0){
            cout<<"empty";
            return -1;
        }
        int el=st[start];
        if(curr_size==1){
            start=end=1;
        }
        else{
            start=(start+1)%size;
        }
        curr_size--;
        return el;
    }
    int top(){
        if(curr_size==0){
            cout<<"empty";
            return -1;
        }
        return st[start];
    }
    int getsize(){
        return curr_size;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front: " << q.top() << endl;
    cout << "Popped: " << q.pop() << endl;
    cout << "Front now: " << q.top() << endl;
    q.push(40);
    q.push(50);
    cout << "Front finally: " << q.top() << endl;
    return 0;
}

//IMPLEMENT STACK USING LL
class Node{
    public:
    Node* next;
    int data;
    Node(int x){
        data=x;
        next=nullptr;
    }
};

class Stack{
    Node* top;
    int size;
    public:
    Stack(){
        top=nullptr;
        size=0;
    }
    void push(int x){
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
        size++;
    }
    void pop(){
        if(top==nullptr){
            cout<<"empty";
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
        size--;
    }
    int peek(){
        if(top==nullptr){
            cout<<"empty";
            return -1;
        }
        return top->data;
    }
    int getsize(){
        return size;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.peek() << endl;
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;
    cout << "Size: " << s.getsize() << endl;
    return 0;
}



class Node{
    public:
    Node* next;
    int data;
    Node(int x){
        data=x;
        next=nullptr;
    }
};
class Queue{
    Node* start;
    Node* end;
    int size;
    public:
    Queue(){
        start=end=nullptr;
        size=0;
    }
    void push(int x){
        Node* temp= new Node(x);
        if(start==nullptr){
            start=end=temp;
        }
        else{
            end->next=temp;
            end=temp;
        }
        size++;
    }
    int pop(){
        if(start==nullptr){
            cout<<"empty";
            return -1;
        }
        Node* temp=start;
        int el=temp->data;
        start=start->next;
        delete temp;
        size--;

        if(start==nullptr) end=nullptr;
        return el;
    }
    int top(){
        return start->data;
    }
    int getsize(){
        return size;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front: " << q.top() << endl;
    cout << "Popped: " << q.pop() << endl;
    cout << "Front now: " << q.top() << endl;
    cout << "Size: " << q.getsize() << endl;
    return 0;
}


*/