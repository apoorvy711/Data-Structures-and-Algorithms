#include <bits/stdc++.h>
using namespace std;

string solve(string &str){
    for(int i=0;i<str.length();i++){
        if(str[i]=='Z'){
            str[i]='A';
        }
        else if(str[i]=='z'){
            str[i]='a';
        }
        else if(isalpha(str[i])){
            str[i]=str[i]+1;
        }
    }
    return str;
}

int main(){
    string str = "abcdxyz";
    string result =solve(str);
    cout << "New String: " << result << endl;
    return 0;
}