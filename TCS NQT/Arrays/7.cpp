#include<bits/stdc++.h>
using namespace std;

int sum_el(vector<int>&arr){
    int n=arr.size();
    int sum=0;
    for(auto x:arr){
        sum+=x;
    }
    return sum;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    int ans=sum_el(arr);
    cout<<ans;
    return 0;
}