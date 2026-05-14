#include <bits/stdc++.h>
using namespace std;


string largestWord(string &s){
    string word="";
    string largest="";
    for(int i=0;i<s.length();i++){
        if(s[i] !=' '){
            word+=s[i];
        }
        else{
            if(word.length() > largest.length()){
                largest=word;
            }
            word="";
        }
    }
    if(word.length() > largest.length()){
        largest=word;
    }
    return largest;
}
int main() {
    string s = "I love programming very much";
    string ans = largestWord(s);
    cout << "Largest word: " << ans;
    return 0;
}