#include<bits/stdc++.h>
using namespace std;

void solve(int len, string &s){
    int vowels=0;
    int conso=0;
    int spaces=0;
    for(int i=0;i<len;i++){
        s[i]=towlower(s[i]);
    }
    for(int i=0;i<len;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
            vowels++;
        }
        else if(s[i]>='a' && s[i]<='z'){
            conso++;
        }
        else if(s[i]==' '){
            spaces++;
        }
    }
    cout<<vowels<<endl;
    cout<<conso<<endl;
    cout<<spaces<<endl;
}

int main(){
    string s="Take u forward is Awesome";
    int len=s.length();
    solve(len,s);
    return 0;
}



