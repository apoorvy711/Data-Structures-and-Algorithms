#include<bits/stdc++.h>
using namespace std;

string longest_prefix(vector<string> & strs){
    if(strs.empty()) return "";

    sort(strs.begin(),strs.end());

    string first=strs[0];
    string last=strs.back();
    string prefix="";

    for(int i=0;i<first.size();i++){
        if(first[i]==last[i]){
            prefix+=first[i];
        }
        else{
            break;
        }
    }
    return prefix;
}

int main(){
    vector<string> strs;
    int n;
    cout<<"the number of strings in vector are:";
    cin>>n;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        strs.push_back(s);
    }
    string result=longest_prefix(strs);
    cout<<"the longest prefix is"<<result<<endl;
    return 0;
}