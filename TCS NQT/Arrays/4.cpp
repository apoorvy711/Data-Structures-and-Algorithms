#include<bits/stdc++.h>
using namespace std;

vector<int>rev_arr(vector<int>&arr, int n){
    int p1=0;
    int p2=arr.size()-1;
    while(p1<p2){
        swap(arr[p1],arr[p2]);
        p1++;
        p2--;
    }
    return arr;
}

int main(){
    vector<int>arr={2,3,4,5,7,8,10};
    int n=7;
    vector<int>ans=rev_arr(arr,n);
    for(auto a:ans){
        cout<<a<<" ";
    }
    return 0;
}