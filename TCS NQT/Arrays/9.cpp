#include<bits/stdc++.h>
using namespace std;

int avge(vector<int>&arr){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int avgee=sum/n;
    return avgee;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    int ans=avge(arr);
    cout<<ans;
    return 0;
}