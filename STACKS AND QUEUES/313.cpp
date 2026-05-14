#include <bits/stdc++.h>
using namespace std;

//CELEBRITY PROBLEM
int celebrity(vector<vector<int>>&matrix){
    int n=matrix.size();
    int top=0;
    int down=n-1;

    while(top < down){
        if(matrix[top][down]==1){
            top++;
        }
        else if(matrix[down][top]==1){
            down--;
        }
        else{
            top++;
            down--;
        }
        if(top>down) return -1;
        for(int i=0;i<n;i++){
            if(i==top) continue;
            if(matrix[top][i]==0 || matrix[i][top]==1){
                continue;
            }
        }
    }
    return top;
}

int  main(){
    vector<vector<int>>matrix={{0,1,1,0},
                               {0,0,0,0},
                               {0,1,0,0},
                               {1,1,0,0}};
    int ans=celebrity(matrix);
    cout<<"the celerity is  "<<ans;
    return 0;

}