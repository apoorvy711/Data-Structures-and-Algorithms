#include<bits/stdc++.h>
using namespace std;
/*
//MOVE ZEROES TO END
void zero_end(int arr[],int n){
    for(int i=0;i<n-2;i++){
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
}

int main(){
    int arr[]={1,0,3,4,6,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    zero_end(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//KADANE ALGO
int kadane(int arr[], int n){
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"the array is";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=kadane(arr,n);
    cout<<ans;
    return 0;
}


//TWO SUM
pair<int,int>two_sum(int arr[], int n, int target){
    sort(arr,arr+n);
    int i=0;
    int j=n-1;
    int sum=0;
    while(i<j){
        sum=arr[i]+arr[j];
        if(sum==target){
            return {arr[i],arr[j]};
        }
        else if(sum<target){
            i++;
        }
        else{
            j--;
        }
    }
    return {-1,-1};
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int target;
    cin>>target;
    cout<<"the array is:"<<" ";
    for(int i=0;i<n;i++){
        cin>>arr[i];   
    }
    pair<int,int>ans=two_sum(arr,n,target);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}

//FIND DUPLICATES
vector<int> duplicates(int arr[], int n){
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    vector<int>res;
    for(auto it:mpp){
        if(it.second>1){
            res.push_back(it.first);
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"the array is:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans=duplicates(arr,n);
    for(auto x:ans){
        cout<<x;
    }
    return 0;
}

//MAJORITY ELEMENT
int majori(int arr[], int n){
    int cnt=1;
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            el=arr[i];
            cnt=1;
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el){
            cnt1++;
        }
    }
    if(cnt1 > n/2.0){
        return el;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"the array is";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=majori(arr,n);
    cout<<ans;
    return 0;
}

//DUTCH SORT
vector<int>sortii(int arr[], int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    vector<int>res(arr,arr+n);
    return res;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"the array is";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans=sortii(arr,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

//BUY AND SELL
int max_profit(int arr[], int n){
    int mini=arr[0];
    int profit=0;
    for(int i=0;i<n;i++){
        int cost=arr[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,arr[i]);
    }
    return profit;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"the array is";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=max_profit(arr,n);
    cout<<ans;
    return 0;
}

//MAX PRODUCT SUB ARRAY
int max_product(int arr[], int n){
    int maxi=arr[0];
    int currMax=arr[0];
    int currMin=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<0){
            swap(currMax,currMin);
        }
        currMax=max(arr[i],currMax*arr[i]);
        currMin=min(arr[i],currMin*arr[i]);
        maxi=max(maxi,currMax);
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"the array is";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=max_product(arr,n);
    cout<<ans;
    return 0;
}

//3 SUM
vector<vector<int>> max_product(int arr[], int n){
    sort(arr,arr+n);
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int>temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k+1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"the array is";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>ans=max_product(arr,n);
    for(auto x:ans){
        cout<<"[";
        for(auto it:x){
            cout<<" "<<it<<" ";
        }
        cout<<"]";
    }
    return 0;
}

//MERGE TWO SORTED ARRAYS WITHOUT EXTRA SPACE
void merge(int arr1[], int arr2[], int n, int m){
    int i=n-1;
    int j=0;
    while(i>=0 && j<m){
        if(arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
            j++;
            i--;
        }
        else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);

}

int main(){
    int arr1[]={1,3,5,7};
    int arr2[]={2,4,6,8};
    int n=4;
    int m=4;
    merge(arr1,arr2,n,m);
    for(auto x:arr1) cout<<x<<" ";
    cout<<endl;
    for(auto x:arr2) cout<<x<<" ";
    return 0;
}

*/




