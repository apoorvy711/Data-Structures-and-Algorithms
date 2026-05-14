#include<bits/stdc++.h>
using namespace std;

//Search in a sorted 2D matrix
//BRUTE
bool Search_element(vector<vector<int>> &matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==target){
                return true;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>> matrix={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Search_element(matrix,8)==true ? cout<<"TRUE\n": cout<<"FALSE\n";
    return 0;
}

//BETTER
bool binary_search(vector<int> &matrix,int target){
    int n=matrix.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(matrix[mid] == target) return true;
        else if( target > matrix[mid]) low=mid+1;
        else high=mid-1;
    }
    return false;
}
bool Search_element(vector<vector<int>> &matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        if(matrix[i][0] <= target && target <= matrix[i][m-1]){
            return binary_search(matrix[i],target);
        }
    }
    return false;
    
}
int main(){
    vector<vector<int>> matrix={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Search_element(matrix,8)==true ? cout<<"TRUE\n": cout<<"FALSE\n";
    return 0;
}

//OPTIMAL
bool Search_element(vector<vector<int>> &matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size();
    int low=0;
    int high=n*m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;
        if(matrix[row][col] == target) return true;
        else if(target > matrix[row][col] ) low=mid+1;
        else high=mid-1;
    }
    return false;
}
int main(){
    vector<vector<int>> matrix={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Search_element(matrix,8)==true ? cout<<"TRUE\n": cout<<"FALSE\n";
    return 0;
}