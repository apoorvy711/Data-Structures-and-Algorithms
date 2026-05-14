#include<bits/stdc++.h>
using namespace std;

//FIND THE SMALLEST DIV
//BRUTE
int smallest_div(vector<int> &arr,int limit){
    int n=arr.size();
    int maxi=*max_element(arr.begin(),arr.end());
    for(int d=1;d<maxi;d++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum +=ceil((double)(arr[i])/(double)(d));
        }
        if(sum<=limit){
            return d;
        }
    }
    return -1;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    int limit=8;
    int ans=smallest_div(arr,limit);
    cout<<"the smallest divisor is "<<ans;
    return 0;
}
/*
//OPTIMAL
int sumByD(vector<int> &arr,int div){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum +=ceil((double)(arr[i])/(double)(div));
    }
    return sum;
}
int smallest_div(vector<int> &arr,int limit){
    int n=arr.size();
    int low=1;
    int maxi=*max_element(arr.begin(),arr.end());
    int high=maxi;
    int ans=0;
    if(n>limit) return -1;
    while(low<=high){
        int mid=(low+high)/2;
        if(sumByD(arr,mid)<=limit){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    int limit=8;
    int ans=smallest_div(arr,limit);
    cout<<"the smallest divisor is "<<ans;
    return 0;
}
    */