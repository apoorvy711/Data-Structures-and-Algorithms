#include<bits/stdc++.h>
using namespace std;

//Kth Missing Positive Number
//BRUTE
int Missing_number(vector<int> &arr,int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
           k++;
        }
        else{
           break;
        }
    }  
    return k;
}
int main(){
    vector<int> arr={4,7,9,10};
    int n=4;
    int k=7;
    int ans=Missing_number(arr,n,k);
    cout<<"the missing number is"<<ans;
    return 0;
}
/*
//OPTIMAL
int Missing_number(vector<int> &arr,int n,int k){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing_no=arr[mid]-(mid+1);
        if(missing_no <= k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return k+high+1;
}
int main(){
    vector<int> arr={4,7,9,10};
    int n=4;
    int k=4;
    int ans=Missing_number(arr,n,k);
    cout<<"the missing number is"<<ans;
    return 0;
}
*/
