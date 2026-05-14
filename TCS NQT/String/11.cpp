#include<bits/stdc++.h>
using namespace std;

void string_freq(string &s){
    map<char,int>mpp;
    for(auto x:s){
        mpp[x]++;
    }
    for(auto it:mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
}

int main(){
    string s="aabcddee";
    string_freq(s);
    return 0;
}