#include<bits/stdc++.h>
using namespace std;

double kTHELEMENT_OFTWOSORTEDARRAYS(vector<int>nums1,vector<int>nums2,int k){
    for(int i=0;i<nums2.size();i++){
        nums1.push_back(nums2[i]);
    }
    double median=0;
    sort(nums1.begin(),nums1.end());
    int N=nums1.size();
    return nums1[k-1];
}

int main(){
    vector<int>nums1={1,3,4,7,10,12};
    vector<int>nums2={2,3,6,15};
    int k=4;
    double ans=kTHELEMENT_OFTWOSORTEDARRAYS(nums1,nums2,k);
    cout<<ans;
    return 0;
}