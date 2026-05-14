#include<bits/stdc++.h>
using namespace std;

void jo_cchihye_mc(int s,int n){
    int num=s;
    int sum=0;
    int w=s%100;
    if(w==n){
        cout<<"YES MC";
    }
    else{
        cout<<"NO MC";
    }
}

void square_nikal_bsdk(int n){
    int s=0;
    s=n*n;
    jo_cchihye_mc(s,n);
}

int main(){
    int n=25;
    square_nikal_bsdk(n);
    return 0;
}