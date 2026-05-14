#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void merge_sort(vector<int>& arr,int low,int high){
    if(low>=high) return ;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

double median_twosorted(vector<int>& nums1, vector<int>& nums2){
    for(int i=0;i<nums2.size();i++){
        nums1.push_back(nums2[i]);
    }
    merge_sort(nums1,0,nums1.size()-1);
    int N=nums1.size();
    if(N%2==0){
        double median=(nums1[N/2 - 1] + nums1[N/2]) / 2.0;
        return median;
    }
    else{
        double median=nums1[N/2];
        return median;
    }
}
 

int main(){
    vector<int>nums1={1,3,4,7,10,12};
    vector<int>nums2={2,3,6,15};
    double ans=median_twosorted(nums1,nums2);
    cout<<ans;
    return 0;
}