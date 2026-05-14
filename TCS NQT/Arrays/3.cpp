#include<bits/stdc++.h>
using namespace std;
//second minimum
int min_Second(int arr[],int n){
    int min=arr[0];
    int s_min=-1;
    for(int i=1;i<n;i++){
        if(min > arr[i]){
            s_min=min;
            min=arr[i];
        }
    }
    return s_min;
}

int main(){
    int arr[]={2,3,4,5,7,8,10};
    int n=7;
    int ans=min_Second(arr,n);
    cout<<ans;
    return 0;
}

//second maximum
int max_Second(int arr[],int n){
    int max=arr[0];
    int s_max=-1;
    for(int i=1;i<n;i++){
        if(max > arr[i]){
            s_max=max;
            max=arr[i];
        }
    }
    return s_max;
}

int main(){
    int arr[]={2,3,4,5,7,8,10};
    int n=7;
    int ans=max_Second(arr,n);
    cout<<ans;
    return 0;
}
