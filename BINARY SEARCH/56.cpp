#include<bits/stdc++.h>
using namespace std;
/*
//KOKO BANANA EATING ALGO
//BRUTE
int find_max(vector<int> &arr){
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);
    }
    return ans;
}
int calculate_hours(vector<int> &arr,int hourly){
    int totalH=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        totalH +=ceil((double)(arr[i])/(double)(hourly));
    }
    return totalH;
}
int minimum_rate_of_eating_bananas(vector<int> &arr,int h){
    int maxi=find_max(arr);

    for(int i=1;i<=maxi;i++){
        int req_time=calculate_hours(arr,i);
        if(req_time <= h){
            return i;
        }   
    }
    return maxi;
}
int main(){
    vector<int> arr={7,15,6,3};
    int h=8;
    int ans=minimum_rate_of_eating_bananas(arr,h);
    cout<<"the minimum rate of eating all the bananas is:"<<ans;
    return 0;
}
*/
//OPTIMAL
int find_max(vector<int> &arr){
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);
    }
    return ans;
}
int calculate_hours(vector<int> &arr,int hourly){
    int totalH=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        totalH +=ceil((double)(arr[i])/(double)(hourly));
    }
    return totalH;
}
int minimum_rate_of_eating_bananas(vector<int> &arr,int h){
    int low=1;
    int high=find_max(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int totalH=calculate_hours(arr,mid);
        if(totalH <= h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    vector<int> arr={7,15,6,3};
    int h=8;
    int ans=minimum_rate_of_eating_bananas(arr,h);
    cout<<"the minimum rate of eating all the bananas is:"<<ans;
    return 0;
}