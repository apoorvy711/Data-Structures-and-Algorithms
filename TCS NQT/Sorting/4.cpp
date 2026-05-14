#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr, int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>= low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int>&arr,int low,int high){
    if(low<high){
        int Pindex=partition(arr,low,high);
        qs(arr,low,Pindex-1);
        qs(arr,Pindex+1,high);
    }
}

int main(){
    vector<int> arr={4,5,3,1,6,7,8,0};
    int n=arr.size();
    cout<<"array before sorting"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    qs(arr,0,n-1);
    cout<<"array after sorting"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    return 0;
}