#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &arr, int k){
    int rsum=0;
    int lsum=0;
    int maxSUM=0;
    int n=arr.size();
    for(int i=0;i<k;i++){
        lsum=lsum+arr[i]; 
        
    }
    maxSUM=lsum;
    for(int i=1;i<=k;i++){
        lsum=lsum-arr[k-i];
        rsum=rsum+arr[n-i];

        maxSUM=max(maxSUM,lsum+rsum);
    }
    return maxSUM;
}

int main(){
    vector<int>arr={6,2,3,4,7,2,1,7,1};
    int k=4;
    int ans=func(arr,k);
    cout<<"the maximum sum is "<<ans;
    return 0;
}