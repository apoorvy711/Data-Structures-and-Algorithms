#include<bits/stdc++.h>
using namespace std;

vector<int> med(vector<int>&arr){
    int n=arr.size();
    vector<int>res;
    if(n%2==0){
        res.push_back(arr[n/2-1]);
        res.push_back(arr[n/2]);
    }
    else{
        res.push_back(arr[n/2]);
    }
    return res;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    vector<int>ans=med(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}