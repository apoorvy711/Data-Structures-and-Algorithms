#include<bits/stdc++.h>
using namespace std;

void factorss(int n){
    vector<int>arr;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            arr.push_back(i);
            if(i != n/i){
                arr.push_back(n/i);
            }
        }
    }
    for(int x:arr){
        cout<<x<<" ";
    }
}

int main(){
    int n=36;
    factorss(n);
    return 0;
}