#include<bits/stdc++.h> 
using namespace std;
string sums(vector<int> &arr,int target){
     int left=0;
     int right=arr.size()-1;
     sort(arr.begin(),arr.end());
     while(left<right){
        int sum=arr[left] + arr[right];
        if(sum==target){
            return "yes";
        }
        else if (sum<target){
            left++;
        }
        else {
            right--;
        }
     }
     return "NO";
}
int main(){
    vector<int> arr = {2, 3, 4, 1, 6, 8};
    int target;
    cout <<"Enter target sum: ";
    cin >>target;
    string ans =sums(arr, target);
    cout<<"The result is:"<<ans<<endl;
    return 0;
}