#include <bits/stdc++.h>
using namespace std;
/*
void largest(vector<int>&arr,int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(arr[i],maxi);
    }
    cout<<maxi;
}

int main(){
    vector<int>arr={3,2,4,6,7,1,0,9};
    int n=arr.size();
    largest(arr,n);
    return 0;
}


int slargest(vector<int>&arr,int n){
    int s_larg=-1;
    int larg=0;
    for(int i=0;i<n;i++){
        if(arr[i]>larg){
            s_larg=larg;
            larg=arr[i];
        }
    }
    return s_larg;
}

int main(){
    vector<int>arr={3,2,4,6,7,1,0,9};
    int n=arr.size();
    int ans=slargest(arr,n);
    cout<<ans;
    return 0;

}

bool is_sort(vector<int>&arr, int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    //vector<int>arr={3,2,4,6,7,1,0,9};
    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    bool ans=is_sort(arr,n);
    if(ans==true) cout<<"yes";
    else cout<<"no";
    return 0;
}

vector<int>remove_dupl(vector<int>&arr, int n){
    int el=-1;
    vector<int>res;
    for(int i=1;i<n;i++){
        if(arr[i-1]==arr[i]){
            continue;
        }
        else res.push_back(arr[i-1]);
    }
    return res;
}

int main(){
    vector<int>arr={1,2,3,3,4,5,6,6,7,8,9,9};
    int n=arr.size();
    vector<int>ans=remove_dupl(arr,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}


bool linear_s(vector<int>&arr, int k){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==k) return true;
    }
    return false;
}
int main(){
    vector<int>arr={1,2,4,3,6,9};
    int k=5;
    bool ans=linear_s(arr,k);
    if(ans) cout<<"YES";
    else cout<<"NO";
    return 0;
}

vector<int>unionn(vector<int>&arr1,vector<int>&arr2){
    set<int>res;
    vector<int>ans;
    for(auto x:arr1){
        res.insert(x);
    }
    for(auto x:arr2){
        res.insert(x);
    }
    ans=vector<int>(res.begin(),res.end());
    return ans;
}
int main(){
    vector<int>arr1={1,2,4,3,6,9};
    vector<int>arr2={6,7,8,9};
    vector<int>ans=unionn(arr1,arr2);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

vector<int>intersec(vector<int>&arr1,vector<int>&arr2){
    vector<int>res;
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            if(arr1[i]==arr2[j]){
                res.push_back(arr1[i]);
            }
        }
    }
    return res;
}

int main(){
    vector<int>arr1={1,2,4,3,6,9};
    vector<int>arr2={6,7,8,9};
    vector<int>ans=intersec(arr1,arr2);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

vector<int>left_rotate(vector<int>&arr, int k){
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin(),arr.end());
    return arr;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    int k=2;
    vector<int>ans=left_rotate(arr,k);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

vector<int>move_zero(vector<int>&arr, int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}

int main(){
    vector<int>arr={1,0,2,8,0,0,4,2,3,0,7,7};
    int n=arr.size();
    vector<int>ans=move_zero(arr,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

int miss_num(vector<int>&arr, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int summ=0;
    for(int i=1;i<=n+1;i++){
        summ+=i;
    }
    int miiis=summ-sum;
    return miiis;
}

int main(){
    vector<int>arr={1,2,3,5};
    int n=arr.size();
    int k=miss_num(arr,n);
    cout<<k<<" ";
    return 0;
}

int max_ones(vector<int>&arr, int n){
    int cnt=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]==1) cnt++;
    }
    return cnt;
}

int main(){
    vector<int>arr={1,2,1,3,1,4,5,6,1,1};
    int n=arr.size();
    int ans=max_ones(arr,n);
    cout<<ans<<" ";
    return 0;
}

vector<int>ones_twice(vector<int>&arr){
    int n=arr.size();
    vector<int>res;
    unordered_map<int,int>el;
    for(auto x:arr){
        el[x]++;
    }
    for(auto x:el){
        if(x.second== 2){
            res.push_back(x.first);
        }
        if(x.second == 1){
            res.push_back(x.first);
        }
    }
    return res;
}

int main(){
    vector<int>arr={1,1,2,3,4,5,6,2,8,8,8};
    vector<int>ans=ones_twice(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
} 

int long_sub(vector<int>&arr , int k){
    int i=0;
    int n=arr.size();
    int j=arr.size()-1;
    int maxi=0;
    int sum=0;
    for(int r=0;r<n;r++){
        sum+=arr[r];
        if(sum>k){
            sum-=arr[i];
            i++;
        }
        if(sum==k){
            maxi=max(maxi,r-i+1);
        }
    }
    return maxi;
}

int main(){
    vector<int>arr={10, 5, 2, 7, 1, 9};
    int k=15;
    int ans=long_sub(arr,k);
    cout<<ans<<" ";
    return 0;
}
  
bool rest(vector<int>&arr , int n, int k){
    int i=0;
    int j=n-1;
    int sum=0;
    while(i<j){
        sum=arr[i]+arr[j];
        if(sum>k){
            j--;
        }
        else{
            i++;
        }
        if(sum==k) return true;
    }
    return false;
}

int main(){
    vector<int>arr={2,6,5,8,11};
    int n=arr.size();
    int k=14;
    bool ans=rest(arr,n,k);
    if(ans) cout<<"YES";
    else cout<<"NO";
    return 0;
}

vector<int>sorti(vector<int>&arr , int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid <= high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1) mid++;
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return arr;
}

int main(){
    vector<int>arr={1, 0, 2, 1, 0};
    int n=arr.size();
    vector<int>ans=sorti(arr,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}


int majori(vector<int>&arr, int n){
    int el=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if(el==arr[i]) cnt++;
        else cnt--;
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(el==arr[i]) cnt1++;
    }
    if(cnt1 > n/2) return el;
    return -1;
}

int main(){
    vector<int>arr={1,4,2,3,4,4,4};
    int n=arr.size();
    int ans=majori(arr,n);
    cout<<ans<<" ";
    return 0;
}


vector<int>by_sign(vector<int>&arr, int n){
    int posI=0;
    int negI=1;
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ans[negI]=arr[i];
            negI +=2;
        }
        else{
            ans[posI]=arr[i];
            posI+=2;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={1, 2, -4, -5};
    int n=arr.size();
    vector<int>ans=by_sign(arr,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

vector<int>next_perm(vector<int>&arr, int n){
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1) reverse(arr.begin(),arr.end()) ;
    for(int i=n-1;i>index;i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr.begin()+index+1,arr.end());
    return arr;
}

int main(){
    vector<int>arr={2,1,5,4,3,0,0};
    int n=arr.size();
    vector<int>ans=next_perm(arr,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

vector<int>leaderss(vector<int>&arr, int n){
    int maxi=INT_MIN;
    vector<int>ans;
    for(int i=n-1;i>0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi=max(maxi,arr[i]);
    }
    return ans;
}

int main(){
    vector<int>arr={4, 7, 1, 0};
    int n=arr.size();
    vector<int>ans=leaderss(arr,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

int longss(vector<int>&arr, int n){
    int maxi=1;
    int cnt=1;
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        if(arr[i-1]+1==arr[i]){
            cnt++;
        }
        else if(arr[i-1] !=arr[i]){
            cnt=1;
        }
        maxi=max(maxi,cnt);
    }
    return maxi;
}

int main(){
    vector<int>arr={100, 4, 200, 1, 3, 2};
    int n=arr.size();
    int ans=longss(arr,n);
    cout<<ans<<" ";
    return 0;
}


void rotate(vector<vector<int>>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
}

int main(){
    vector < vector < int > > arr={ {1,2,3},{4,5,6},{7,8,9}};
    rotate(arr);
    cout<<"rotated image"<<endl;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

vector<int>spiralOrder(vector<vector<int>>&matrix){
    vector<int>ans;
    int top=0;
    int right=matrix[0].size()-1;
    int left=0;
    int bottom=matrix.size()-1;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>matrix = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    vector<int>result=spiralOrder(matrix);
    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}

int countss_subarray(vector<int>&arr, int k){
    int n=arr.size();
    int sum=0;
    int i=0;
    int maxi=INT_MIN;
    for(int j=0;j<n;j++){
        sum+=arr[j];
        if(sum>k){
            sum-=arr[i];
            i++;
        }
        if(sum==k){
            maxi=max(maxi,j-i+1);
        }
    }
    return maxi;
}

int main(){
    vector<int>arr={3, 1, 1,1, 4};
    int k=6;
    int ans =countss_subarray(arr,k);
    cout<<ans<<" ";
    return 0;
}


int nCr(int n, int r){
    long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}

vector<vector<int>>pascal_tri(int n){
    vector<vector<int>>ans;
    for(int row=1;row<=n;row++){
        vector<int>tempRow;
        for(int col=1;col<=row;col++){
            tempRow.push_back(nCr(row-1,col-1));
        }
        ans.push_back(tempRow);
    }
    return ans;
}

int main(){
    int n=5;
    vector<vector<int>>ans=pascal_tri(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

vector<int>major_elII(vector<int>&arr){
    int n=arr.size();
    int cnt1=0;
    int cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1==0 && el1 !=arr[i]){
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && el2 !=arr[i]){
            cnt2=1;
            el2=arr[i];
        }
        else if(el1==arr[i]){
            cnt1++;
        }
        else if(el2==arr[i]){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==arr[i]) cnt1++;
        if(el2==arr[i]) cnt2++;
    }
    int mini=int(n/3)+1;
    vector<int>listi;
    if(cnt1 >= mini) listi.push_back(el1);
    if(cnt2 >= mini) listi.push_back(el2);
    return listi;
}

int main(){
    vector<int>arr={11, 33, 33, 11, 33, 11};
    vector<int>ans=major_elII(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

vector<vector<int>>three_some(vector<int> arr, int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0){
                k--;
            }
            else if(sum<0){
                j++;
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
    vector<int> arr={-1, 0, 1, 2, -1, -4 };
    int n=arr.size();
    vector<vector<int>>ans=three_some(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<"["<< " ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}

vector<vector<int>>four_sum(vector<int> arr,int target){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]) continue;
            int k=j+1;
            int m=n-1;
            while(k<m){
                long sum=arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[m];
                if(sum==target){
                vector<int>temp={arr[i],arr[j],arr[k],arr[m]};
                ans.push_back(temp);
                k++;
                m--;
                while(k<m && arr[k]==arr[k-1]) k++;
                while(k<m && arr[m]==arr[m+1]) m--;
                }
                else if(sum<target) k++;
                else m--;
            }
        }
    }
    return ans;
}
    
int main(){
    vector<int> arr={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>>ans=four_sum(arr,target);
    for(int i=0;i<ans.size();i++){
        cout<<"["<< " ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}

vector<vector<int>>mergee(vector<vector<int>>&arr, int n){
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>arr={{1,3},{2,6},{8,10},{15,18}};
    int n=arr.size();
    vector<vector<int>>ans=mergee(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}


vector<int>merge_two(vector<int>&nums1,int n,vector<int>&nums2, int m){
    int p1=n-1;
    int p2=m-1;
    int p=n+m-1;
    while(p1>=0 && p2>=0){
        nums1[p--]=(nums1[p1]>nums2[p2])?nums1[p1--]:nums2[p2--];
    }
    while(p2>=0){
        nums1[p--]=nums2[p2--];
    }
    return nums1;
}

int main(){
    vector<int>nums1={1,2,3,0,0,0};
    vector<int>nums2={2,5,6};
    int n=3;
    int m=3;
    vector<int>ans=merge_two(nums1,n,nums2,m);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}


//ROTATE K ELEMNENTS

vector<int>rotate_k(vector<int>arr,int k){
    int n=arr.size();
    vector<int>temp;
    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    for(int i=0;i<temp.size();i++){
        arr[n-k+i]=temp[i];
    }
    return arr;

}

int main(){
    vector<int>arr={1,2,3,4,5};
    int k;
    cin>>k;
    vector<int>ans=rotate_k(arr,k);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

//KADANE ALGORITHM
int kadane_algo(vector<int>arr){
    int n=arr.size();
    long long maxi=LLONG_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main(){
    vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
    int ans=kadane_algo(arr);
    cout<<ans;
    return 0;
}

int kadane_algo(vector<int>arr){
    int n=arr.size();
    long long maxi=LLONG_MIN;
    int sum=1;
    for(int i=0;i<n;i++){
        sum*=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main(){
    vector<int>arr={2,3,-2,4};
    int ans=kadane_algo(arr);
    cout<<ans;
    return 0;
}
*/

