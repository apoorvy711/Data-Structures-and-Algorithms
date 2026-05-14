#include<bits/stdc++.h>
using namespace std;

//Convert digits/numbers to words
int main(){
    string s="507";
    string words[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(char c:s){
        cout<<words[c - '0'] <<" ";
    }
    return 0;
}