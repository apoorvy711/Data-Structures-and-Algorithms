#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n<=0) return 1;
    return n*fact(n-1);
}
int final(int n,int r){
    int ans=fact(n)/fact(n-r) ;
    return ans;
}

int main(){
    int n=5;
    int r=3;
    int ans=final(n,r);
    cout<<ans;
    return 0;
}