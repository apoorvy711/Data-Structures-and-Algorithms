#include<bits/stdc++.h>
using namespace std;
//Minimum days to make M bouquets
//BRUTE
bool possible(vector<int> &arr,int day,int k,int m){
    int n=arr.size();
    int cnt=0;
    int noOfB=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=day){
            cnt++;
        }
        else{
            noOfB +=(cnt/k);
            cnt=0;
        }
    }
    noOfB +=(cnt/k);
    return noOfB>=m;
} 
int rose_garden(vector<int> &arr,int k,int m){
    int mini=INT_MAX, maxi=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }
    for(int i=mini;i<maxi;i++){
        if (possible(arr,i,k,m)){
            return i;
        }
    }
     return -1;
}
int main(){
    vector<int> arr={7, 7, 7, 7, 13, 11, 12, 7};
    int k=3;
    int m=2;
    int ans=rose_garden(arr,k,m);
    if(ans ==-1){
        cout<<"we cannot make the bouquets";
    }
    else{
        cout<<"the number of bouquets  possible are:"<<ans;
    }
    return 0;
}

//OPTIMAL
bool possible(vector<int> &arr,int day,int k,int m){
    int n=arr.size();
    int cnt=0;
    int noOfB=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=day){
            cnt++;
        }
        else{
            noOfB +=(cnt/k);
            cnt=0;
        }
    }
    noOfB +=(cnt/k);
    return noOfB>=m;
} 
int rose_garden(vector<int> &arr,int k,int m){
    int mini=INT_MAX, maxi=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }
    int low=mini;
    int high=maxi;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(arr,mid,k,m)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    vector<int> arr={7, 7, 7, 7, 13, 11, 12, 7};
    int k=3;
    int m=2;
    int ans=rose_garden(arr,k,m);
    if(ans ==-1){
        cout<<"we cannot make the bouquets";
    }
    else{
        cout<<"the number of bouquets  possible are:"<<ans;
    }
    return 0;
}