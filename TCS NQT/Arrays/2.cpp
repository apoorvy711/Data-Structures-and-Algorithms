#include<bits/stdc++.h>
using namespace std;

int min_no(int arr[],int n){
    int larg=arr[0];
    for(int i=1;i<n;i++){
        if(larg < arr[i]){
            larg=arr[i];
        }
    }
    return larg;
}

int main(){
    int arr[]={2,3,4,5,7,8,10};
    int n=7;
    int ans=min_no(arr,n);
    cout<<ans;
    return 0;
}