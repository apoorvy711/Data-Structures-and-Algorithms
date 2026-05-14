#include <bits/stdc++.h>
using namespace std;

//BRUTE
int func(vector<int>&arr ,int k){
    int n=arr.size();
    int maxLEN=0;

    for(int i=0;i<n;i++){
        int zeros=0;
        for(int j=i;j<n;j++){
            if(arr[j]==0){
                zeros++;
            }
            if(zeros<=k){
                int len=j-i+1;
                maxLEN=max(maxLEN,len);
            }
            else{
                break;
            }

        }
    }
    return maxLEN;
}

int main(){
    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    int ans=func(arr,k);
    cout<<"the answer is "<<ans;
    return 0;
}

///BETTER
int func(vector<int>&arr ,int k){
    int n=arr.size();
    int r=0;
    int l=0;
    int zeros=0;
    int maxLEN=0;
    while(r<n){
        if(arr[r]==0) zeros++;

        while(zeros>k){
            if(arr[l]==0) zeros--;
            l++;
        }
        if(zeros<=k){
            int len=r-l+1;
            maxLEN=max(maxLEN,len);
        }
        r++;
    }
    return maxLEN;
}

int main(){
    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    int ans=func(arr,k);
    cout<<"the answer is "<<ans;
    return 0;
}

//OPTIMAL
int func(vector<int>&arr ,int k){
    int n=arr.size();
    int r=0;
    int l=0;
    int zeros=0;
    int maxLEN=0;
    while(r<n){
        if(arr[r]==0) zeros++;

        if(zeros>k){
            if(arr[l]==0) zeros--;
            l++;
        }
        if(zeros<=k){
            int len=r-l+1;
            maxLEN=max(maxLEN,len);
        }
        r++;
    }
    return maxLEN;
}

int main(){
    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    int ans=func(arr,k);
    cout<<"the answer is "<<ans;
    return 0;
}

