#include<bits/stdc++.h>
using namespace std;

//BINARY SEARCH IN 2D MATRIX
//BRUTE
bool Search_element(vector<vector<int>> &matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>> matrix={{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    Search_element(matrix,8)== true ? cout<<"TRUE\n" : cout<<"FALSE\n";
    return 0;    
}

//BETTER
bool binary_search(vector<int>&matrix,int target){
    int n=matrix.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(matrix[mid]==target) return true;
        else if(matrix[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}
bool Search_element(vector<vector<int>> &matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0;i<n;i++){
        bool flag=binary_search(matrix[i],target);
        if(flag) return true;
    }
    return false;
}
int main(){
    vector<vector<int>> matrix={{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    Search_element(matrix,8)== true ? cout<<"TRUE\n" : cout<<"FALSE\n";
    return 0;    
}

//OPTIMAL
bool Search_element(vector<vector<int>> &matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size(); 
    int row=0;
    int col=n-1;
    while(row<n && col >=0){
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) row++;
        else col--;
    } 
    return false;
}
int main(){
    vector<vector<int>> matrix={{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    Search_element(matrix,8)== true ? cout<<"TRUE\n" : cout<<"FALSE\n";
    return 0;    
}

