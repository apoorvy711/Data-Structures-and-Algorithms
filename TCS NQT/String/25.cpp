#include <bits/stdc++.h>
using namespace std;

string casess(string &s){
    for(int i=0;i<s.length();i++){
        if(islower(s[i])){
            s[i]=toupper(s[i]);
        }
        else{
            s[i]=tolower(s[i]);
        }
    }
    return s;
}

int main(){
    string s="aeJDHjenJQnfoO";
    string ans=casess(s);
    cout<<ans<<" ";
    return 0;
}