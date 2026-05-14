#include<bits/stdc++.h>
using namespace std;

int revers(int n){
    int revN=0;
    while(n>0){
        int w=n%10;
        revN=(revN*10)+w;
        n=n/10;
    }
    return revN;
}

int main(){
    int n=1345;
    int ans=revers(n);
    cout<<"reversed number is"<<ans;
    return 0;
}