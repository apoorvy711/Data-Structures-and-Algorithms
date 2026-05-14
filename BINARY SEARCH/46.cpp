#include<bits/stdc++.h>
using namespace std;

//LOWER BOUND
int lb(vector<int> &arr,int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {3, 5, 8, 15, 19};
    int n=5;
    int target=9;
    int ans=lb(arr,n,target);
    cout<<"the lower bound is the index:"<<ans;
    return 0;
}

//UPPER BOUND
int ub(vector<int> &arr,int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, target = 9;
    int ans=ub(arr,n,target);
    cout<<"the upper bound is the index:"<<ans;
    return 0;
}

//Search Insert Position
//exactly same as LB OR can be said this question is a application of LB
int insert_target(vector<int> &arr,int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1, 2, 4, 7};
    int n=4;
    int target=6;
    int ans=insert_target(arr,n,target);
    cout<<"the lower bound is the index:"<<ans;
    return 0;
}


//Floor and Ceil in Sorted Array
int find_floor(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low <= high){
        int mid=(low+high)/2;
        if(arr[mid]<=target){
            ans=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int find_coil(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low <= high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=arr[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
pair<int,int> get_FLOOR_and_COIL(int arr[],int n,int target){
    int f=find_floor(arr,n,target);
    int c=find_coil(arr,n,target);
    return make_pair(f,c);
}
int main(){
    int arr[]={3, 4, 4, 7, 8, 10};
    int n=6;
    int target=5;
    pair <int,int> ans=get_FLOOR_and_COIL(arr,n,target);
    cout<<"the floor of the array is "<<" "<<ans.first<<" and " <<"the coil of the array is "<<" "<<ans.second<<endl;
    return 0;
 
}