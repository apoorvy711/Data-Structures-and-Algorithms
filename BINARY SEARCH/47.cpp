#include<bits/stdc++.h>
using namespace std;

//Last occurrence in a sorted array
//BRUTE
int last_occurence(vector<int> &arr,int n,int target){
    int res=-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i] == target){
            res=i;
            break;
        }
    }
    return res;
}
int main(){
    vector<int> arr={3,4,13,13,13,20,40};
    int n=7;
    int target=13;
    cout<<last_occurence(arr,n,target);
    return 0;
}

//OPTIMAL
int last_occurence(vector<int> &arr,int n,int target){
    int start=0;
    int end=n-1;
    int res=-1;
    while(start <= end){
        int mid=start + ((end-start)/2);
        if(arr[mid] == target){
            res=mid;
            start=mid+1;
        }
        else if (target < arr[mid]){
            end=mid-1;
        }
        else {
            start=mid+1;
        }
    }
    return res;
}
int main(){
    vector<int> arr={3,4,13,13,13,20,40};
    int n=7;
    int target=13;
    cout<<last_occurence(arr,n,target);
    return 0;
}

//COUNT OCCURENCES OF A A GIVEN NUMBER
//BRUTE
int counts(vector<int> &arr,int n,int target){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i] == target){
           cnt++;
        }
    }
    return cnt;
}
int main(){
    vector<int> arr={2, 4, 6, 8, 8, 8, 11, 13};
    int n=8;
    int target=8;
    int ans=counts(arr,n,target);
    cout<<"the count is"<<ans;
    return 0;
}


//OPTIMAL
int first_occurence(vector<int> &arr,int n,int target){
    int low=0;
    int high=n-1;
    int first=-1;
    while(low <= high){
        int mid=low +((high-low)/2);
        if(arr[mid]==target){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid] < target){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return first;
}
int last_occurence(vector<int> &arr,int n,int target){
    int low=0;
    int high=n-1;
    int last=-1;
    while(low <= high){
        int mid=low +((high-low)/2);
        if(arr[mid]==target){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid] < target){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return last;
}
pair<int,int> first_and_last_position(vector<int> &arr,int n,int target){
    int first=first_occurence(arr,n,target);
    if(first==-1) return {-1,-1};
    int last=last_occurence(arr,n,target);
    return {first,last};
}
int counts(vector<int> &arr,int n,int target){
    pair<int,int> ans=first_and_last_position(arr,n,target);
    if(ans.first == -1){
        return 0;
    }
    return (ans.second - ans.first +1);
}
int main(){
    vector<int> arr={2, 4, 6, 8, 8, 8, 11, 13};
    int n=8;
    int target=8;
    int ans=counts(arr,n,target);
    cout<<"the number of occurences of the target is"<<ans;
    return 0; 
}
