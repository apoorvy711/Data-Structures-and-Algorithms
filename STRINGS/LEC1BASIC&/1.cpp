#include<bits/stdc++.h>
using namespace std;

//STACK APPROACH
string removeouterparanthesis(string s){
    string result="";
    stack<char>st;
    for(auto c:s){
        if(c=='('){
            if(!st.empty()){
                result=result+c;
            }
            st.push(c);
        }    
        else{
            st.pop();
            if(!st.empty()){
            result=result+c;
            }
        }
    }
    return result;
 }

int main(){
    string s;
    cout<<"enter the string:";
    cin>>s;

    string output=removeouterparanthesis(s);

    cout<<"after removing outer strings:"<<output<<endl;
    return 0;
}

//COUNTER APPROACH
string removeouterparanthesis(string s){
    int depth=0;
    string result="";

    for(auto c:s){
        if(c=='('){
            if(depth >0) result=result+c;
            depth++;
        }
        else{
            depth--;
            if(depth >0) result=result+c;
        }
    }
    return result;
}

int main(){
    string s;

    cout<<"enter the string:";
    cin>>s;

    string output=removeouterparanthesis(s);

    cout<<"after removing outer strings:"<<output<<endl;
    return 0;
}

