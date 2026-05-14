#include<bits/stdc++.h>
using namespace std;

string printsubstrings(string &s){
    int n=s.length();
    int total=0;

    cout<<"all subtrings are :";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<s.substr(i,j-i+1)<<endl;
            total++;
        }
    }
    cout<<"the total number of sub strings are:"<<total;
}

int main(){
    string s="abc";
    printsubstrings(s);
    return 0;
}