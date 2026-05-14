#include<bits/stdc++.h>
using namespace std;

int maxDepth(string &s){
    int cnt=0;
    int maxi=INT_MIN;
    for(auto ch:s){
        if(ch=='(') cnt++;
        if(ch==')') cnt--;
        maxi=max(maxi,cnt);
    }
    return maxi;
}


int main(){

    string s;
    cout<<"the string is :";
    cin>>s;

    int result=maxDepth(s);
    cout<<"the maximum depth of the string is "<<result;
    return 0;
}