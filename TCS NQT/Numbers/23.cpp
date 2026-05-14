#include<bits/stdc++.h>
using namespace std;

int gcd_no(int a,int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
    }
    if(a==0) return b;
    return a;
}

int main(){
    int a=12;
    int b=7;
    int ans=gcd_no(a,b);
    cout<<ans;
    return 0;
}