#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n<=0) return 1;
    return n*fact(n-1);
}

void numb(int n){
    int sum=0;
    int num=n;
    while(n>0){
        int w=n%10;
        sum=sum+fact(w);
        n=n/10;
    }
    if(sum==num){
        cout<<"strong number";
    }
    else{
        cout<<"not an strong number";
    }
}

int main(){
    int n=145;
    numb(n);
    return 0;
}