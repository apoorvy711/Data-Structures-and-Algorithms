#include <bits/stdc++.h>
using namespace std;

char max_char(string &s){
    map<char,int>m;
    for(auto it:s){
        m[it]++;
    }
    int maxfreq=0;
    char maxchar='\0';
    for(auto it:m){
        if(it.second > maxfreq){
            maxfreq=it.second;
            maxchar=it.first;
        }
    }
    return maxchar;
}

int main(){
    string s="apple";
    char ans=max_char(s);
    cout<<ans<<" ";
    return 0;
}