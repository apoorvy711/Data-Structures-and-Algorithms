#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr, int k){
    int n=arr.size();
    int r=0;
    int l=0;
    int count=0;
    int ans=0;
    unordered_map<int,int>hash;
    while(r<n){
        hash[arr[r]]++;
        if(hash[arr[r]]==1){
            count++;
        }

        while(count>k){
            hash[arr[l]]--;
            if(hash[arr[l]]==0){
                count--;
            }
            l++;

        }
        ans+=(r-l+1);
        r++;
    }
    return ans;
}

int sub_arrays(vector<int>&arr, int k){
    return solve(arr,k)-solve(arr,k-1);
}

int main(){
    vector<int>arr={1,2,1,3,4};
    int k=3;
    int ans=sub_arrays(arr,k);
    cout<<"the number of sub arrays possible are "<<ans;
    return 0;
}