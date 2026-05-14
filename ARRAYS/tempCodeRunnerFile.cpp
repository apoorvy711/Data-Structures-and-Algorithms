
int nCr(int n,int row){
    long res=1;
    for(int i=0;i<n;i++){
        res=res *(n-i);
        res = res/(i+1);
    }
    return res;
}
vector<vector<int>> pascal_triangle(int n){
    vector<vector<int>> ans;
    for(int row=1;row<n;row++){
        int tempRow;
        for(int col=1;col<row;col++){
            tempRow.push_back(nCr(row-1,col-1));
        }
        ans.push_back(tempRow);
    }
    return ans;
}
int main(){
    int n=5;
    vector<vector<int> > ans = pascal_triangle(n);
    cout<<"the pascal triangle with "<<n<<" rows :\n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}