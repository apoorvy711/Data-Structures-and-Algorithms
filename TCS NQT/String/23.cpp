#include <bits/stdc++.h>
using namespace std;

int countWords(string &s){
    int spaces=0;
    for(auto ch:s){
        if(ch == ' '){
            spaces++;
        }
    }
    return spaces+1;
}

int main() {
    string s = "Hello this is test";
    cout <<countWords(s);
    return 0;
}