#include <bits/stdc++.h>
using namespace std;

void sortii_merge(string &s, int low,int mid, int high){
    int left=low;
    int right=mid+1;
    vector<char>temp;
    while(left<=mid && right <=high){
        if(s[left]<=s[right]){
            temp.push_back(s[left]);
            left++;
        }
        else{
            temp.push_back(s[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(s[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(s[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        s[i]=temp[i-low];
    }
}

void sortii(string &s, int low, int high){
    if(low>=high) return ;
    int mid=(low+high)/2;
    sortii(s,low,mid);
    sortii(s,mid+1,high);
    sortii_merge(s,low,mid,high);

}

int main(){
    string s="bdca";
    int n=s.size();
    sortii(s,0,n-1);
    cout<<s;
    return 0;
}
