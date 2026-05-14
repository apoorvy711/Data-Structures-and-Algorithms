#include <bits/stdc++.h>
using namespace std;

string remove_str(string &str1, string &str2){
    string res="";
    unordered_map<char,bool>m;
    for(auto it:str2){
        m[it]=true;
    }
    for(auto it:str1){
        if(!m[it]){
            res +=it;
        }
    }
    return res;
}

int main(){
    string str1 = "computer";
    string str2 = "cat";
    string ans=remove_str(str1,str2);
    cout<<ans<<" ";
    return 0;
}