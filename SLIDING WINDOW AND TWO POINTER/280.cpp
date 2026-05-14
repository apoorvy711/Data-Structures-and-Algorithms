#include <bits/stdc++.h>
using namespace std;

int count__most(vector<int>&arr,int goal){
    int n=arr.size();
    int r=0;
    int l=0;
    int sum=0;
    int count=0;
    while(r<n){
        sum=sum+arr[r];
        while(sum>goal){
            sum=sum-arr[l];
            l++;
        }
        count=count+(r-l+1);
        r++;
    }
    return count;
}

int sub_array(vector<int>&arr,int goal){
    
    return count__most(arr,goal)-count__most(arr,goal-1);

}

int main(){
    vector<int>arr={1,0,1,0,1};
    int goal=2;
    int ans=sub_array(arr,goal);
    cout<<"the number of sub arrays possile are "<<ans;
    return 0;
}