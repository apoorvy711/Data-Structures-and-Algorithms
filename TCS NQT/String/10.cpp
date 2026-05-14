#include<bits/stdc++.h>
using namespace std;

string capitalize(string s){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(i==0 || s[i-1]==' '){
            s[i]=toupper(s[i]);
        }
        if(i==n-1 || s[i+1]==' '){
            s[i]=toupper(s[i]);
        }
    }
    return s;
}

int main(){
    string s = "hello world from dsa";
    cout << capitalize(s);
    return 0;
}