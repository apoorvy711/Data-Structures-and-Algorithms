#include <bits/stdc++.h>
using namespace std;

vector<int> majority_Element(vector<int> v ) {
    int el1=INT_MIN;
    int el2=INT_MIN;
    int cnt1=0;
    int cnt2=0;
    int n=v.size();
    for(int i=0;i<n;i++){
        if(cnt1==0 && el1 !=v[i]){
            cnt1=1;
            el1=v[i];
        }
        else if(cnt2==0 && el1 !=v[i]){
            cnt2=1;
            el2=v[i];
        }
        else if(v[i] == el1){
            cnt1++;
        }
        else if(v[i] == el2){
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0, cnt2=0;
    for(int i=0 ; i<n ; i++){
        if(v[i]==el1){
            cnt1++;
        }
        if(v[i]==el2){
            cnt2++;
        }
    }

    int mini = int(n / 3) + 1;
    vector<int> ls;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);
    return ls;
}
int main(){
    vector<int> arr={11, 33, 33, 11, 33, 11};
    int n=arr.size();
    vector<int> ans=majority_Element(arr);
    cout<<"the ans is";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}