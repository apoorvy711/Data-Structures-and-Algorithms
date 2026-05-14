#include <bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    void warshall(vector<vector<int>>&mat,int v){
        int N=mat.size();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mat[i][j]==-1){
                    mat[i][j]=1e8;
                }
                if (i == j) mat[i][j] = 0;
            }
        }

        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mat[i][j]==1e8){
                    mat[i][j]=-1;
                }
            }
        }
    }
};

int main(){
    int v=4;
    vector<vector<int>>mat(v,vector<int>(v,-1));
    mat[0][1]=2;
    mat[1][0]=1;
    mat[3][0]=3;
    mat[3][1]=5;
    mat[3][2]=4;
    mat[1][2]=3;
   
    Solution obj;
    obj.warshall(mat,v);
    for(auto &i:mat){
        for(auto &j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

*/

void warshall(vector<vector<int>>&mat, int v){
    int n=mat.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1){
                mat[i][j]=1e8;
            }
            if(i==j) mat[i][j]=0;
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1e8){
                mat[i][j]=-1;
            }
        }
    }

}

int main(){
    int v=4;
    vector<vector<int>>mat(v,vector<int>(v,-1));
    mat[0][1]=2;
    mat[1][0]=1;
    mat[3][0]=3;
    mat[3][1]=5;
    mat[3][2]=4;
    mat[1][2]=3;
    warshall(mat,v);
    for(auto &i:mat){
        for(auto &j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
*/