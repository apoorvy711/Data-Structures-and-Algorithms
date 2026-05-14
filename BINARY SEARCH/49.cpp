#include<bits/stdc++.h>
using namespace std;

//Search Element in Rotated Sorted Array II
bool sorted_array(vector<int> &arr,int target){
    int n=arr.size();
    for(int i=0;i<n;i++){
        arr[i]=target;
        return "TRUE";
    }
    return "FALSE";
}
int main(){
    vector<int> arr={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target=3;
    bool ans=sorted_array(arr,target);
    if(!ans){
        cout<<"target is not present";
    }
    else {
        cout<<"target is present";
    }
    return 0;
}


//OPTIMAL
bool sorted_array(vector<int> &arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+high/2;
        if(arr[mid] == target){
            return true;
        }
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low=mid+1;
            high=mid-1;
            continue;
        }
        if(arr[low]<= arr[mid]){
            if(arr[low]<= target && target <=arr[mid]){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        else {
            if(arr[mid] <=target && target <= arr[high]){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        
        }
    }
    return false;
}
int main(){
    vector<int> arr={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target=3;
    bool ans=sorted_array(arr,target);
    if(!ans){
        cout<<"target is not present";
    }
    else {
        cout<<"target is present";
    }
    return 0;
}
