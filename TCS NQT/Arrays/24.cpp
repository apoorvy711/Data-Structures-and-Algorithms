#include <bits/stdc++.h>
using namespace std;
/*
bool subset(int el,vector<int>&arr2,int n){
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr2[mid] == el)
            return true;
        else if (arr2[mid] < el)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

bool isSubset(vector<int>&arr1,int n,vector<int>&arr2,int m ){
    if(n > m) return false;
    sort(arr2.begin(),arr2.begin()+n);
    for(int i=0;i<m;i++){
        bool present=subset(arr1[i],arr2,n);
        if(present ==false) return false;
    }
    return true;
}
*/









bool isset(int el,vector<int>arr2, int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr2[mid]==el){
            return true;
        }
        else if(arr2[mid]<el){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return false;
}

bool isSubset(  vector<int>arr1,int n,vector<int>arr2, int m){
    if(n>m) return false;
    sort(arr2.begin(),arr2.end());
    for(int i=0;i<m;i++){
        bool present=isset(arr1[i],arr2,n);
        if(present==false) return false;
    }
    return true;
}

int main(){
    vector<int>arr1={1,3,4,5,2};
    vector<int>arr2{2,4,3,1,7,5,15};
    int n=arr1.size();
    int m=arr2.size();
    bool ans=isSubset(arr1,n,arr2,m);
    if(ans==true) cout<<"yes";
    else cout<<"NO";
    return 0;
}