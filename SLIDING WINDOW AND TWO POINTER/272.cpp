#include <bits/stdc++.h>
using namespace std;

//CONSTANT WINDOW
//example of sum 
 vector<int>func( vector<int> &arr,int k){
    int n=arr.size();
    vector<int>result;
    int r=0;
    int l=0;
    int sum=0;
    while(r<n){
        sum+=arr[r];
        if(r-l+1<k){
            r++;
        }
        else if(r-l+1==k){
            result.push_back(sum);
            sum=sum-arr[l];
            r++;
            l++;
        }
    }
    return result;
}

int main(){
    vector<int>arr={-1,2,3,4,5,-1};
    int k=4;
    vector<int>ans=func(arr,k);
    cout<<"the sums are :";
    for(int &it:ans){
        cout<<it<<" ";
    }
    return 0;
}



//LONGEST SUBARRAY
//BRUTE
int func1( vector<int> &arr,int k){
    int maxLEN=0;
    int n=arr.size();
   
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum<=k){
                maxLEN=max(maxLEN,j-i+1);
            }
            else if(sum>k) {
                break;
            }
        }
    }
    return maxLEN;
}

int main(){
    vector<int> arr={2,5,1,7,10};
    int k=14;
    int ans=func1(arr,k);
    cout<<"the length of the longest subarray is"<<ans;
    return 0;
}

//BETTER
int func2(vector<int> &arr,int k){
    int l=0;
    int r=0;
    int n=arr.size();
    int sum=0;
    int maxLEN=0;
    while(r<n){
        sum+=arr[r];
        while(sum>k && l<=r){
            sum=sum-arr[l];
            l++;
        }
        if(sum<=k){
            maxLEN=max(maxLEN,r-l+1);
        }
        r++;
    }
    return maxLEN;
}

int main(){
    vector<int> arr={2,5,1,7,10};
    int k=14;
    int ans=func2(arr,k);
    cout<<"the length of the longest subarray is"<<ans;
    return 0;
}

//OPTIMAL
int func3(vector<int> &arr,int k){
    int l=0;
    int r=0;
    int n=arr.size();
    int sum=0;
    int maxLEN=0;
    while(r<n){
        sum+=arr[r];
        if(sum>k && l<=r){
            sum=sum-arr[l];
            l++;
        }
        if(sum<=k){
            maxLEN=max(maxLEN,r-l+1);
        }
        r++;
    }
    return maxLEN;
}

int main(){
    vector<int> arr={2,5,1,7,10};
    int k=14;
    int ans=func3(arr,k);
    cout<<"the length of the longest subarray is"<<ans;
    return 0;
}

