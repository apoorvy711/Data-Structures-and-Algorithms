#include<bits/stdc++.h>
using namespace std;

bool ifanagram(string &s,string &t){

    if(s.length() !=t.length()){
        return false;
    }

    unordered_map<char,int>MAP;
    for(int i=0;i<s.length();i++){
        MAP[s[i]]++;
    }

    for(int i=0;i<t.length();i++){
        if(MAP.find(t[i]) != MAP.end()){
            MAP[t[i]]--;
        }
        else{
            return false;
        }
    }

    for(auto temp:MAP){
        if(temp.second !=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s,t;
    cout<<"the first string s is :";
    cin>>s;
    cout<<endl;
    cout<<"the second string t is :";
    cin>>t;
    cout<<endl;
    if(ifanagram(s,t)){
        cout<<"the strings are anagram";
    }
    else{
        cout<<"the strings are not anagram";
    }
    cout<<endl;
    return 0;
}