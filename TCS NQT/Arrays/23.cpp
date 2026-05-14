#include <bits/stdc++.h>
using namespace std;

int find_pos(vector<int>&arr, int k){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low <= high){
        int mid=(low + high) /2;
        if(arr[mid]>k){
            high=mid-1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else{
            ans=mid;
            break;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={6, 7, 9, 5, 3, 10};
    int k=5;
    int ans=find_pos(arr,k);
    cout<<ans<<" ";
    return 0;
}