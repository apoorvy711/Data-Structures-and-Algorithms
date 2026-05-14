#include<bits/stdc++.h>
using namespace std;

//IMPLEMENT STACK USING ARRAYS

class Stack{
    int st[10];
    int top=-1;
    public:
    void push(int x){
        if(top>=9){
            cout<<"overflow condition";
            return;
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
            cout<<"empry stack";
            return;
        }
        top=top-1;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.peek();
    s.pop();
    s.push(40);
    cout<<s.peek();
    return 0;
}