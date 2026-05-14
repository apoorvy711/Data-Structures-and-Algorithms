#include<bits/stdc++.h>
using namespace std;

void isprime(vector<int>&arr){
    vector<int>res;
    int size_arr=arr.size();
    for(int i=0;i<size_arr;i++){
        int cnt=0;
        int el=arr[i];
        for(int j=1;j<=el;j++){
            if(el%j==0){
                cnt=cnt+1;
            }
        }
        if(cnt==2){
            res.push_back(el);
        }
    }
    for(int x:res){
        cout<<x<<" ";
    }
}

void factorss(int n){
    vector<int>arr;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            arr.push_back(i);
            if( i != n/i){
                arr.push_back(n/i);
            }
        }
    }
    isprime(arr);
}



int main(){
    int n=36;
    factorss(n);
    return 0;
}