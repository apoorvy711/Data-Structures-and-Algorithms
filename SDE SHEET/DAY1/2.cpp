#include<bits/stdc++.h>
using namespace std;

int ncr(int n,int r){
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return (int)(res);
}

vector<vector<int>>pascalTriangle(int row){
    vector<vector<int>>ans;
    for(int i=0;i<row;i++){
        vector<int>temp;
        for(int j=0;j<=i;j++){
            temp.push_back(ncr(i,j));
        }
        ans.push_back(temp);
    }   
    return ans;
}


int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}