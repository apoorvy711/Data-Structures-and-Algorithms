#include<bits/stdc++.h>
using namespace std;
//Find the row with maximum number of 1's
//BRUTE
int max_ones_in_rows(vector<vector<int>> &matrix,int n,int m){
    int cnt_max=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int cnt_ones=0;
        for(int j=0;j<m;j++){
            cnt_ones +=matrix[i][j];
        }
        if(cnt_ones > cnt_max){
            cnt_max=cnt_ones;
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



//OPTIMAL
int lower_bound(vector<int> &matrix,int n,int x){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(matrix[mid] >= x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int max_ones_in_rows(vector<vector<int>> &matrix,int n,int m){
    int cnt_max=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int cnt_ones=m - lower_bound(matrix[i],m,1);
        if(cnt_ones >=cnt_max){
            cnt_max=cnt_ones;
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

