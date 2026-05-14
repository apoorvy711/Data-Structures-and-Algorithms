#include<bits/stdc++.h>
using namespace std;

bool ifRotated(string &s, string &t){
    if(s.length() != t.length()){
        return false;
    }
    string combined =s+s;
    int index=combined.find(t);
    if(index==-1){
        return false;
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
    if(ifRotated(s,t)){
        cout<<"the strings are rotatedly present";
    }
    else{
        cout<<"the strings are not rotatedly present";
    }
    cout<<endl;
    return 0;
}