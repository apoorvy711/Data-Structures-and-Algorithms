#include<bits/stdc++.h>
using namespace std;

//ITERATIVE CODE IMPLEMENTATION
int bs(vector<int> &arr,int n,int target){
    int low=0,high=n-1;
    while(low <=high){
        int mid=(low+high)/2;
        if(arr[mid] == target){
            return mid;
        } 
        else if(target > arr[mid]){ 
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return -1;
}    
int main(){
    vector<int> arr={3,4,6,7,9,12,16,17};
    int n=arr.size();
    int target=13;
    int ans=bs(arr,n,target);
    if(ans !=-1){
        cout<<"the element is present at index "<<ans;
    }
    else {
        cout<<"the element is not present";
    }
    return 0;
}

//RECURSIVE APPROACH
int bs(vector<int> &arr,int low,int high,int target){
    if(low>high){
        return -1;
    }
    int mid=(low+high)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(target>arr[mid]){
        return bs(arr,mid+1,high,target);
    }

    return bs(arr,low,high-1,target);

}
int main(){
    vector<int> arr={3,4,6,7,9,12,16,17};
    int n=arr.size();
    int target=13;
    int low=0;
    int high=n-1;
    int ans=bs(arr,low,high,target);
    if(ans !=-1){
        cout<<"the element is present at index "<<ans;
    }
    else {
        cout<<"the element is not present";
    }
    return 0;
}