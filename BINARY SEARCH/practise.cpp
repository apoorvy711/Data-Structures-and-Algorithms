#include<bits/stdc++.h>
using namespace std;
/*
int last_occ(vector<int>arr, int x){
    int n=arr.size();
    int start=0;
    int end=n-1;
    int res=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==x){
            res=mid;
            start=mid+1;
        }
        else if(arr[mid]>x){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}
int first_occ(vector<int>arr, int x){
    int n=arr.size();
    int start=0;
    int end=n-1;
    int res=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==x){
            res=mid;
            end=mid-1;
        }
        else if(arr[mid]>x){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}

int count_occ(vector<int>arr, int x){
    int l_occ=last_occ(arr,x);
    int f_occ=first_occ(arr,x);
    return (l_occ-f_occ+1);
}

int main(){
    vector<int>arr={3, 4, 13, 13, 13, 20, 40};
    int x=13;
    int ans=count_occ(arr,x);
    cout<<ans;
    return 0;
}


bool sorted(vector<int>arr, int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return true;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low=mid+1;
            high=mid-1;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=target && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
}

int main(){
    vector<int>arr={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target=3;
    bool ans=sorted(arr,target);
    if(ans) cout<<"true";
    else cout<<"false";
    return 0;
}



int findMin(vector<int> arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            ans=min(ans,arr[low]);
            break;
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={4, 5, 6, 7, 0, 1, 2, 3};
    int ans=findMin(arr);
    cout<<"the minimum of the array is"<<ans;
    return 0;
}



int rotate_times(vector<int>arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int index=-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                ans=arr[low];
                index=low;
            }
            break;
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                ans=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(arr[mid]<ans){
                ans=arr[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    return index;
}

int main(){
    vector<int> arr={4, 5, 6, 7, 0, 1, 2, 3};
    int ans=rotate_times(arr);
    cout<<"rotation by "<<ans;
    return 0;
}



int search_single_element(vector<int> arr){
    int n=arr.size();
    if(arr[0] !=arr[1]) return arr[0];
    if(arr[n-2] !=arr[n-1]) return arr[n-1];
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }

        if((mid%2==1  && arr[mid]==arr[mid-1]) || mid%2==0 && arr[mid]==arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr={1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans=search_single_element(arr);
    cout<<"the single element is "<<ans;
    return 0;
}


int peak_element(vector<int> arr){
    int n=arr.size();
    if(arr[0]>arr[1]) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }
        else if(arr[mid]>arr[mid-1]){
            low=mid+1;
        }
        else high=mid-1;
    }
    return -1;
}

int main(){
    vector<int> arr={1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans=peak_element(arr);
    cout<<"the peak element is  at index:"<<ans;
    return 0;
}


int sqrooot(int n){
    int low=0;
    int high=n;
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid * mid <=n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n=28;
    int ans=sqrooot(n);
    cout<<ans;
    return 0;

}


int func(int mid, int n, int m){
    long long ans=-1;
    for(int i=0;i<=n;i++){
        ans=ans*mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}

int Nth_root(int n, int m){
    int low=1;
    int high=m;
    while(low<=high){
        int mid=(low+high)/2;
        int midN=func(mid,n,m);
        if(midN==1) return mid;
        else if(midN==0) low=mid+1;
        else high=mid-1; 
    }
    return -1;
}

int main(){
    int n=4;
    int m=69;
    int ans=Nth_root(n,m);
    cout<<ans;
    return 0;
}


int arr_maxi(vector<int> arr){
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);
    }
    return ans;
}

int cal_hours(vector<int>arr, int hourly){
    int totalH=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        totalH+=ceil((double)(arr[i])/(double)(hourly));
    }
    return totalH;
}

int minimum_rate_of_eating_bananas(vector<int> arr, int h){
    int low=1;
    int high=arr_maxi(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int totalHours=cal_hours(arr,mid);
        if(totalHours<=h){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}

int main(){
    vector<int> arr={7,15,6,3};
    int h=8;
    int ans=minimum_rate_of_eating_bananas(arr,h);
    cout<<"the minimum rate of eating all the bananas is:"<<ans;
    return 0;
}


int arr_maxi(vector<int> arr){
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);
    }
    return ans;
}

int sum_nom(vector<int>arr, int mid){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)(arr[i])/(double)(mid));
    }
    return sum;
}

int smalllwest(vector<int>arr, int limit){
    int low=1;
    int high=arr_maxi(arr);
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        int numberrr=sum_nom(arr,mid);
        if(numberrr<=limit){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    int limit=8;
    int ans=smalllwest(arr,limit);
    cout<<ans;
    return 0;
}


bool can_we_place(vector<int>arr,int mid, int cows){
    int cntcows=1;
    int last=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]-last>=mid){
            last=arr[i];
            cntcows++;
        }
        if(cntcows>=cows) return true;
    }
    return false;
}

int cowspossible(vector<int>arr, int cows){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int low=1;
    int high=arr[n-1]-arr[0];
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(can_we_place(arr,mid,cows)==true){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}

int main(){
    vector<int>arr={0,3,4,7,10,9};
    int cows=4;
    int ans=cowspossible(arr,cows);
    cout<<ans;
    return 0;
}



double kTHELEMENT_OFTWOSORTEDARRAYS(vector<int>nums1,vector<int>nums2,int k){
    for(int i=0;i<nums2.size();i++){
        nums1.push_back(nums2[i]);
    }
    double median=0;
    sort(nums1.begin(),nums1.end());
    int N=nums1.size();
    return nums1[k];
}

int main(){
    vector<int>nums1={1,3,4,7,10,12};
    vector<int>nums2={2,3,6,15};
    int k=4;
    double ans=kTHELEMENT_OFTWOSORTEDARRAYS(nums1,nums2,k);
    cout<<ans;
    return 0;
}



int max_ones_in_rows(vector<vector<int>> matrix, int n ,int m){
    int index=-1;
    int mt_cnt=0;
    for(int i=0;i<n;i++){
        int cnt_ones=0;
        for(int j=0;j<m;j++){
            cnt_ones+=matrix[i][j];
        }
        if(cnt_ones>=mt_cnt){
            mt_cnt=cnt_ones;
            index=i;
        }
    }
    return index;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n=3;
    int m=3;
    cout<<"the row with the maximum 1s are :"<<max_ones_in_rows(matrix,n,m);
    return 0;
}

*/

bool Search_element(vector<vector<int>> matrix, int target){
    int n=matrix.size();
    int m=matrix[0].size();
    int i=0;
    while(i<n){
        if(matrix[i][0]<=target && target<=matrix[i][m-1]){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        i++;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Search_element(matrix,8)==true ? cout<<"TRUE\n": cout<<"FALSE\n";
    return 0;
}