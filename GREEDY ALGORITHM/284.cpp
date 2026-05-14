#include <bits/stdc++.h>
using namespace std;
int func(vector<int>&greed,vector<int>&content){
    int n=greed.size();
    int m=content.size();
    int l=0;
    int r=0;

    sort(greed.begin(),greed.end());
    sort(content.begin(),content.end());

    while(l<n && r<m){
        if(greed[l] <= content[r]){
            l=l+1;
        }
        r=r+1;
    }
    return l;
}

int main(){
    vector<int>greed={1,5,3,3,4};
    vector<int>content={4,2,1,2,1,3};

    int ans=func(greed,content);
    cout<<ans;
    return 0;
}