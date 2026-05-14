#include<bits/stdc++.h>
using namespace std;

/*
bool isValid(string s){
    stack<char>ch;
    for(auto it:s){
        if(it=='(' || it=='{' || it=='[') ch.push(it);
        else{
            if(ch.size()==0) return false;
            char st=ch.top();
            ch.pop();
            if((it==')' && st=='(') || (it=='}' && st=='{') || (it==']' && st=='[')) continue;
            else return false;
        }
    }
    return ch.empty();
}

int main(){
    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}
*/











