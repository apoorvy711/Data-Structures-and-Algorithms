#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=0) return 1;
    int last=fib(n-1);
    int slast=fib(n-2);
    return last +slast ;
}

int main(){
    int n=2;
    int ans=fib(n);
    cout<<ans<<" ";
    return 0;
}