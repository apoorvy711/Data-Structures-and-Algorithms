#include<bits/stdc++.h>
using namespace std;

//Find out how many times the array has been rotated
//BRUTE
int findKrotation(vector<int> &arr){
    int n=arr.size();
    int ans=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<ans){
            ans=arr[i];
            index=i;
        }
    }
    return index;
}
int main(){
    vector<int> arr={4, 5, 6, 7, 0, 1, 2, 3};
    int ans=findKrotation(arr);
    cout<<"the number of rotations are "<<ans;
    return 0;
}

//OPTIMAL
int findKrotation(vector<int> &arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int index=-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=low+high/2;

        //( 4, 5, 6, 7, 0, 1, 2, 3 )
        //if already sorted
        if(arr[low] <=arr[high]){
            if(arr[low] < ans){
                ans=arr[low];
                index=low;
            }
            break;
        }
        
        if(arr[low]<=arr[mid]){
            if(arr[low] < ans){
                ans=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(arr[mid] < ans){
                ans=arr[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    return index;
}
int main(){
    vector<int> arr={4, 5, 6, 7, 0, 1, 2, 3};
    int ans=findKrotation(arr);
    cout<<"the number of rotations are "<<ans;
    return 0;
}