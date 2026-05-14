#include<bits/stdc++.h>
using namespace std;

string charby_freq(string &s){
    unordered_map<char,int>freq;

    for(char c:s){
        freq[c]++;
    }

    vector<pair<char,int>>chars(freq.begin(),freq.end());

    sort(chars.begin(),chars.end(),[](auto &a,auto &b){
        return a.second>b.second;
    });

    string result="";
    for(auto &pair : chars){
        result += string(pair.second,pair.first);
    }
    return result;  
}

int main(){
    string s;
    cout<<"the string is :";
    cin>>s;

    string result=charby_freq(s);
    cout<<"the new string is "<<result;
    return 0;

}