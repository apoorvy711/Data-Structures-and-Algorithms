#include<bits/stdc++.h>
using namespace std;

//BRUTE
int trap_water(  vector<int>&arr){
    int n=arr.size();
    int trappedwater=0;
    for(int i=0;i<n;i++){
        int leftMAX=0;
        int rightMAX=0;
        int j=i;
        while(j>=0){
            leftMAX=max(leftMAX,arr[j]);
            j--;
        }
        j=i;
        while(j<n){
            rightMAX=max(rightMAX,arr[j]);
            j++;
        }
        trappedwater +=min(leftMAX,rightMAX)-arr[i];
    }
    return trappedwater;
}

int  main(){
    vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
    int ans=trap_water(arr);
    cout<<"the trapped water between the bars is "<<ans;
    return 0;
}

//BETTER
int trap_water(  vector<int>&arr){
    int n=arr.size();
    int trappedwater=0;
    int suffix[n];
    int prefix[n];
    prefix[0]=arr[0];
    suffix[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        prefix[i]=max(prefix[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=max(suffix[i+1],arr[i]);
    }
    for(int i=0;i<n;i++){
        trappedwater +=min( prefix[i],  suffix[i])- arr[i];
    }
    return trappedwater; 
}

int  main(){
    vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
    int ans=trap_water(arr);
    cout<<"the trapped water between the bars is "<<ans;
    return 0;
}

//OPTIMAL
int trap_water(  vector<int>&arr){
int n = arr.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (arr[left] <= arr[right]) {
      if (arr[left] >= maxLeft) {
        maxLeft =arr[left];
      } else {
        res += maxLeft - arr[left];
      }
      left++;
    } else {
      if (arr[right] >= maxRight) {
        maxRight = arr[right];
      } else {
        res += maxRight - arr[right];
      }
      right--;
    }
  }
  return res;
}

int  main(){
    vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
    int ans=trap_water(arr);
    cout<<"the trapped water between the bars is "<<ans;
    return 0;
}


