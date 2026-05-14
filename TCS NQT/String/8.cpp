#include<bits/stdc++.h>
using namespace std;

string charac(string &s){
    string res="";
    for(char ch:s){
        char lower=tolower(ch);
        if(lower>='a' && lower<='z'){
            res+=lower;
        }
    }
    return res;
}

int main(){
    string s = "a+((b-c)+d)";
    string ans=charac(s);
    cout<<ans;
    return 0;
}