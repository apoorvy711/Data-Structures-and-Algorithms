#include <bits/stdc++.h>
using namespace std;

//Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle
int nCr(int n,int r){
    long res=1;
    for(int i=0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}
int pascal_triangle(int r,int c){
    int a=nCr(r-1,c-1);
    return a;
}
int main(){
    int r=5;
    int c=3;
    int elements=pascal_triangle(r,c);
    cout<<" the element at position (r,c) is"<<" "<<elements;
    return 0;
}


//Variation 2:Given the row number n. Print the n-th row of Pascal’s triangle.
int nCr(int n,int r){
    long res=1;
    for(int i=0;i<r;i++){
        res =res * (n-i);
        res = res/ (i+1);
    }
    return res;
}
void pascal_triangle(int n){
    for(int c=0;c<n;c++){
        cout<<nCr(n-1,c)<<" ";
    }
    cout<<"\n";
}
int main(){
    int n=5;
    pascal_triangle(n);
    return 0;
}


//Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle
int nCr(int n,int r){
    long res=1;
    for(int i=0;i<r;i++){
        res=res *(n-i);
        res = res/(i+1);
    }
    return res;
}
vector<vector<int>> pascal_triangle(int n){
    vector<vector<int>> ans;
    for(int row=1;row<=n;row++){
        vector<int> tempRow;
        for(int col=1;col<=row;col++){
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