#include<bits/stdc++.h>
using namespace std;

//SORT A STACK
void sorted_insert(stack<int>&st,int num){
    if(st.empty() || (!st.empty() && st.top() > num)){
        st.push(num);
        return ;
    }
    int n=st.top();
    st.pop();
    sorted_insert(st,num);
    st.push(n);
}

void sortStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int num=st.top();
    st.pop();

    sortStack(st);

    sorted_insert(st,num);
}


int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(-5);
    st.push(7);
    st.push(15);

    cout << "Original Stack (top to bottom): ";
    stack<int> temp = st;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
    
    

}