#include<bits/stdc++.h>
using namespace std;

int charac(string &s){
    int sum=0;
    int len=s.size()-1;
    for(char ch:s){
        if(ch>='0' && ch<='9'){
            sum+=ch - '0';
        }
    }
    return sum;
}

int main(){
    string s = "123xyz";
    int ans=charac(s);
    cout<<ans;
    return 0;
}