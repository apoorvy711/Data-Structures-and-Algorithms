#include<bits/stdc++.h>
using namespace std;

void Rearrange_array(vector <int> &A){
    vector<int> pos,neg;
    int p=0,n=0;
    for(int i=0;i<A.size();i++){
        if(A[i] >= 0){
            pos.push_back(A[i]);
        }
        else {
            neg.push_back(A[i]);
        }
    }
        int i=0;
        while(p < pos.size() && n < neg.size()){
            A[i++]=pos[p++];
            A[i++]=neg[n++];
        }
        while(p < pos.size()){
            A[i++]=pos[p++];
        }
        while(n < neg.size()){
            A[i++]=neg[n++];
        }
    }

int main(){
    vector<int> A = {1, 2, -4, -5, 3, -6};
    Rearrange_array(A);
    cout<<"the new array is";
    for(int i=0;i<A.size();i++){
        cout<<A[i];
    }
    return 0;
}