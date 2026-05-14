#include<bits/stdc++.h>
using namespace std;
/*
//BRUTE
stack<pair<int,int>>st;

void push(int val){
    if(st.empty()) st.push({val,val});
    else{
        int MINI=min(val,st.top().second);
        st.push({val,MINI});
    }
}

void pop(){
    if(!st.empty()){
        st.pop();
    }
}

int top(){
    if(!st.empty()){
        return st.top().first;
    }
    return -1;

}

int getMINI(){
    if(!st.empty()){
        return st.top().second;
    }
    return -1;
}

int main(){
    push(12);
    push(15);
    push(10);
    cout<<"the current minimum is "<<getMINI()<<endl;
    pop();
    cout<<"the top element is "<<top()<<endl;
    cout<<"the new min is "<<getMINI()<<endl;
    return 0;
}


*/

//OPTIMAL