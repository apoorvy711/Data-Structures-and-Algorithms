#include<bits/stdc++.h>
using namespace std;

bool ifIsomorphic(string &s, string &t){
    if(s.length() != t.length()){
        return false;
    }
    unordered_map<char,char>mp_s_t;
    unordered_map<char,char>mp_t_s;

    for(int i=0;i<s.length();i++){
        char c1=s[i];
        char c2=t[i];

        if(mp_s_t.count(c1)){
            if(mp_s_t[c1] != c2){
                return false;
            }
        }    
        else{
            mp_s_t[c1] = c2;
        }
    
        if(mp_t_s.count(c2)){
            if(mp_t_s[c2] != c1){
                return false;
            }
        }    
        else{
            mp_t_s[c2] = c1;
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
    if(ifIsomorphic(s,t)){
        cout<<"the strings are isomorphic";
    }
    else{
        cout<<"the strings are not isomorphic";
    }
    cout<<endl;
    return 0;
}