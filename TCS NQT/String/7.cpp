#include<bits/stdc++.h>
using namespace std;

string reversee(string &s){
    int left=0;
    int right=s.length()-1;
    while(left < right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
    return s;
}

int main(){
    string s="Hello World";
    string ans=reversee(s);
    cout<<ans;
    return 0;
}