#include<bits/stdc++.h>
using namespace std;

//MISSING NUMBER
int missingnumber(vector<int> &arr,int N){
    int xor1=0,xor2=0;
    int n=N-1;
    for(int i=0;i<n;i++){
        xor2=xor2^arr[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^N;
    return xor1^xor2;
}
int main(){
    int N=5;
    vector<int> arr={1,2,4,5};
    int ans=missingnumber(arr,N);
    cout<<"the missing number is"<<ans<<endl;
    return 0;
}

//MISSING NUMBER
//USING SUM

int Fmiss(int arr[],int n){
    int sum=(n*(n+1))/2;
    int arrsum=0;
    for(int i=0;i<n-1;i++){
        arrsum +=arr[i];
    }
    return sum-arrsum;
}
int main(){
    int arr[]={1,2,4,5,6};
    int n=6;
    cout<<"missing numer"<<Fmiss(arr,n)<<endl;
    return 0;
}

//USING XOR
int Fmiss(int arr[],int n){
    int xor1=0,xor2=0;
    for(int i=1;i<=n;i++){
        xor1 ^=i;
    }
    for(int i=0;i<n-1;i++){
     xor2^=arr[i];
    }
    return xor1^xor2;
}
int main(){
    int arr[]={1,2,4,5,6};
    int n=6;
    cout<<"missing number"<<Fmiss(arr,n);
    return 0;
}


//MAX CONSECUTIVE ONES
int max_ones(vector<int> &arr,int n){
    int maxi=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else{
            cnt=0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin >>n;
    vector<int> arr(n);
    cout<<"the array is ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=max_ones(arr,n);
    cout<<"the max number of ones is"<<ans<<endl;
    return 0;
}

