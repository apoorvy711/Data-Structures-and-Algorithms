#include<bits/stdc++.h>
using namespace std;

string maxRepeatingWord(string s){
    stringstream ss(s);
    string result="";
    string word;
    int maxrepeat=1;
    while(ss >> word){
        vector<int>freq(26,0);
        for(char x:word){
            freq[x-'a']++;
        }
        int currMax=*max_element(freq.begin(),freq.end());
        if(currMax > maxrepeat){
            maxrepeat=currMax;
            result=word;
        }
    }
    return result;
}

int main() {
    string s = "today is a good day";
    cout << maxRepeatingWord(s);
}