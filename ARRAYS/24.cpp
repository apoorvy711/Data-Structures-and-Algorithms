#include<bits/stdc++.h>
using namespace std;


int max_sum(vector <int> &arr,int n){
     int start=0;
     int current_sum=0;
     int ans_start=-1;
     int ans_end=-1;
     int maxSum=INT_MIN;

     for(int i=0;i<n;i++){
        if(current_sum == 0){
            start=i;
        }
        current_sum+=arr[i];
        
        if(current_sum > maxSum){
            maxSum=current_sum;
            ans_start=start;
            ans_end=i;
        }
        if(current_sum < 0){
            current_sum=0;
        }
        
     }
     cout<<"the array is [ ";
     for(int i=ans_start;i<=ans_end;i++){
        cout<<arr[i]<<" ";
     }
     cout<<" ] "<<endl;
     return maxSum;
}
int  main(){
    vector<int> arr={0,1,1,0,1,2,1,2,0,0,0};
    int n =arr.size(); 
    int ans=max_sum(arr,n);   
    cout<<"the array is"<<ans;
    return 0;
}
