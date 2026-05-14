#include<bits/stdc++.h>
using namespace std;

int sumof(int n){
    if(n==1) return 1;
    return n+sumof(n-1);
}

int main(){
    int n=6;
    int sums=sumof(n);
    cout<<sums<<endl;
    return 0;
}