#include <bits/stdc++.h>
using namespace std;

int sjf(vector<int>&arr){
    sort(arr.begin(),arr.end());
    int t=0;
    int wtTIME=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        wtTIME +=t;
        t +=arr[i];
    }
    return (wtTIME/n);
}

int main(){
    vector<int>arr={4,3,7,1,2};
    int ans=sjf(arr);
    cout<<ans;
    return 0;
}