#include<bits\stdc++.h>
using namespace std;

void printsubsequences(int index, vector<int> &arr,vector<int> temp){
    int n=arr.size();
    if(index == n){
        for(int num:temp){
            cout<<num<<" ";
        }
        cout<<endl;
        return;
    }

    temp.push_back(arr[index]);
    printsubsequences(index+1,arr,temp);

    temp.pop_back();
    printsubsequences(index+1,arr,temp);
}

int main(){
    vector<int> arr={3,1,2};
    vector<int> temp;
    printsubsequences(0,arr,temp);
    return 0;
}


