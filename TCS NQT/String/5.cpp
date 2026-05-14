#include<bits/stdc++.h>
using namespace std;

string remove_spaces(string &s){
    string res="";
    for(char ch:s){
        char lower=tolower(ch);
        if(lower==' '){
            continue;
        }
        res+=ch;
    }
    return res;
}

int main(){
    string s = "Hello World";
    string ans=remove_spaces(s);
    cout<<ans;
    return 0;
}