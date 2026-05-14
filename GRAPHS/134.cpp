#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    vector<vector<int>>flood_fill(int sr,int sc,vector<vector<int>>&image, int newColor){
        int initialColor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,image,newColor,ans,delrow,delcol,initialColor);
        return ans;
    }

    void dfs(int sr,int sc,vector<vector<int>>&image, int newColor,vector<vector<int>>&ans, int delrow[],int delcol[],int initialColor){
        ans[sr][sc]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int mcol=sc+delcol[i];
            if((nrow >=0 && nrow<n) && ( mcol>=0 && mcol<m) && (image[nrow][mcol]==initialColor && ans[nrow][mcol] !=newColor)){
                dfs(nrow,mcol,image,newColor,ans,delrow,delcol,initialColor);
            }
        }
    }
};

int main(){
    vector<vector<int>>image{
	    {1,1,1},
	    {2,2,0},
	    {2,2,2}
	};
    int sr=2;
    int sc=0;
    int newColor=3;
    Solution obj;
    vector<vector<int>>result=obj.flood_fill(sr,sc,image,newColor);
    cout<<"the new matrix is "<<endl;
    for(auto &it:result){
        for(auto &j:it){
            cout<<j<<" ";    
        }
        cout<<endl;
    }
    return 0;
}

*/
void dfs(vector<vector<int>>&image, int sr , int sc, int newcolor,vector<vector<int>>&ans,int initialcolor,int delrow[],int delcol[]){
    int n=image.size();
    int m=image[0].size();
    ans[sr][sc]=newcolor;
    for(int i=0;i<4;i++){
        int r=sr+delrow[i];
        int c=sc+delcol[i];
        if((r>=0 && r<n) && (c>=0 && c<m) && (ans[r][c]!=newcolor) && (image[r][c]==initialcolor)){
            dfs(image,r,c,newcolor,ans,initialcolor,delrow,delcol);
        }
    }
}

vector<vector<int>>floodss(vector<vector<int>>&image, int sr , int sc, int newcolor){
    int n=image.size();
    int m=image[0].size();
    int initialcolor=image[sr][sc];
    vector<vector<int>>ans=image;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    dfs(image,sr,sc,newcolor,ans,initialcolor,delrow,delcol);
    return ans;
}

int main(){
    vector<vector<int>>image={
        {1,1,1},
	    {2,2,0},
	    {2,2,2}
    }; 
    int sr=2;
    int sc=0;
    int newcolor=3;

    vector<vector<int>>ans=floodss(image,sr,sc,newcolor);
    for(auto it:ans){
        for(auto h:it){
            cout<<h<<" ";
        }
        cout<<endl;
    }
    return 0;
}

