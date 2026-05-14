#include<bits/stdc++.h>
using namespace std;

//Split Array - Largest Sum
//BRUTE
int partitions(vector<int> &arr,int sum){
    int n=4;
    int cnt=1;
    int sub_sum=0;
    for(int i=0;i<n;i++){
        if(sub_sum+arr[i]<=sum){
            sub_sum +=arr[i];
        }
        else{
            cnt++;
            sub_sum=arr[i];
        }
    }
    return cnt;
}

int largest_subarray_sum_which_is_minimized(vector<int> &arr,int k){
    int n=4;

    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    for(int sum=low;sum<=high;sum++){
        if(partitions(arr,sum)==k){
            return sum;
        }
    }
    return low;

} 
int main(){
    vector<int> arr={10,20,30,40};
    int k=2;
    int ans=largest_subarray_sum_which_is_minimized(arr,k);
    cout<<"the largest sum which is minimum is "<<ans;
    return 0;
}

//OPTIMAL
int partitions(vector<int> &arr,int sum){
    int n=4;
    int cnt=1;
    int sub_sum=0;
    for(int i=0;i<n;i++){
        if(sub_sum+arr[i]<=sum){
            sub_sum +=arr[i];
        }
        else{
            cnt++;
            sub_sum=arr[i];
        }
    }
    return cnt;
}
int largest_subarray_sum_which_is_minimized(vector<int> &arr,int k){

    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid=(low+high)/2;
        int number=partitions(arr,mid);
        if(number > k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    vector<int> arr={10,20,30,40};
    int k=2;
    int ans=largest_subarray_sum_which_is_minimized(arr,k);
    cout<<"the largest sum which is minimum is "<<ans;
    return 0;
}

//PAINTERS PARTITION
//BRUTE
int painters(vector<int> &arr,int time){
    int cnt_painter=1;
    int boards_sum=0;
    int n=4;
    for(int i=0;i<n;i++){
        if(boards_sum+arr[i] <= time){
            boards_sum +=arr[i];
        }
        else{
            cnt_painter++;
            boards_sum=arr[i];
        }
    }
    return cnt_painter;
}
int largest_time_which_painter_is_minimum(vector<int> &arr,int k){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    int n=4;
    for(int time=low;time<=high;time++){
        if(painters(arr,time)<=k){
            return time;
        }
    }
    return low;
}
int main(){
    vector<int> arr={10, 20, 30, 40};
    int k=2;
    int ans=largest_time_which_painter_is_minimum(arr,k);
    cout<<"largest time which painter took is minimum is "<<ans;
    return 0;
}

//OPTIMAL
int painters(vector<int> &arr,int mid){
    int cnt_painters=1;
    int boards_sum=0;
    int n=4;
    for(int i=0;i<=n;i++){
        if(boards_sum+arr[i] <= mid){
            boards_sum +=arr[i];
        }
        else{
            cnt_painters++;
            boards_sum=arr[i];
        }
    }
    return cnt_painters;
}
int largest_time_which_painter_is_minimum(vector<int> &arr,int k){
     int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    int n=4;

    while(low<=high){
        int mid=(low+high)/2;
        int cnt_painter=painters(arr,mid);
        if(cnt_painter > k ){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    vector<int> arr={10, 20, 30, 40};
    int k=2;
    int ans=largest_time_which_painter_is_minimum(arr,k);
    cout<<"largest time which painter took is minimum is "<<ans;
    return 0;
}



