#include<bits/stdc++.h>
using namespace std;

vector<int>inc_dec(vector<int>&arr, int n){
    sort(arr.begin(),arr.end());

    reverse(arr.begin()+n/2,arr.end());
    return arr;
}

int main(){
    vector<int>arr={2,3,4,5,7,8,10};
    int n=7;
    vector<int>ans=inc_dec(arr,n);
    for(auto a:ans){
        cout<<a<<" ";
    }
    return 0;
}