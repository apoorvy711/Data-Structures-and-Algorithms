#include<bits/stdc++.h>
using namespace std;


string remove_vowel(string &s){
    string res="";
    int len=s.length();
    for(char ch:s){
        char lower=tolower(ch);
        if(lower=='a' || lower=='e' || lower=='i' || lower=='o' || lower=='u' ){
            continue;
        }
        res+=ch;
    }
    return res;
}

int main(){
    string s = "Hello World";
    string ans=remove_vowel(s);
    cout<<ans;
    return 0;
}