#include<bits/stdc++.h>
using namespace std;

void string_freq(string &s){
    map<char,int>mpp;
    for(auto x:s){
        mpp[x]++;
    }
    int maxi=INT_MIN;
    char maxchar='\0';
    for(auto it:mpp){
        if(it.second>maxi){
            maxi=it.second;
            maxchar=it.first;
        }
    }
    cout<<maxchar;
}

int main(){
    string s="aabcddeee";
    string_freq(s);
    return 0;
}