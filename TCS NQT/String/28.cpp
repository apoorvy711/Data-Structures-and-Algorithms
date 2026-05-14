#include<bits/stdc++.h>
using namespace std;

string reverse_string(string s){
    stringstream ss(s);
    stack<string>st;
    string word;
    while(ss >> word){
        st.push(word);
    }
    string result="";
    while(!st.empty()){
        result +=st.top()+" ";
        st.pop();
    }
    result.pop_back();
    return result;
}

int main(){
    string s="god is great";
    string ans=reverse_string(s);
    cout<<ans;
    return 0;
}