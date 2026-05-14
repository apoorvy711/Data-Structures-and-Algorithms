#include<bits/stdc++.h>
using namespace std;

void next_permu(vector<int> &arr,int n){
    int indx=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            indx=i;
            break;
        }
    }
    if(indx == -1){
        reverse(arr.begin(),arr.end());
        return;
    }   
    for(int i=n-1;i>indx;i--){
        if(arr[i]>arr[indx]){
            swap(arr[i],arr[indx]);
            break;
        }
       
    }
    reverse(arr.begin()+indx+1,arr.end());   
}
int main(){
    vector<int> arr={2,1,5,4,3,0,0};
    int n=arr.size();
    next_permu(arr,n);
    cout<<"the new array is";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
    return 0;
  
}