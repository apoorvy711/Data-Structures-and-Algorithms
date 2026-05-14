#include <bits/stdc++.h>
using namespace std;


string dupli(string s){
    unordered_map<char,int>mpp;
    string res="";
    for(auto x:s){
        if(mpp.find(x)==mpp.end()){
            res+=x;
            mpp[x]=1;
        }
    }
    return res;
}

int main(){
    string s="aaccbed";
    string ans=dupli(s);
    cout<<ans;
    return 0;
}
