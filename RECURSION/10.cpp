#include<bits\stdc++.h>
using namespace std;

void combineSUMII(int index, vector<int> &arr,int sum, vector<int> &ds ){
    int n=arr.size();
    if(index==n){
        ds.push_back(sum);
        return;
    }

    combineSUMII(index+1,arr,sum+arr[index],ds);

    combineSUMII(index+1,arr,sum,ds);

}

int main(){
    vector<int> arr={3,1,2};
    vector<int>ds;
    combineSUMII(0,arr,0,ds);
    sort(ds.begin(),ds.end());
    cout << "Combinations are: \n";
    for (auto vec : ds) {
        cout <<vec<<" ";
    }
    return 0;
}

 