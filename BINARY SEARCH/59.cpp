#include<bits/stdc++.h>
using namespace std;
/*
//Capacity to Ship Packages within D Days
//BRUTE
int find_days(vector<int> &weights,int d){
    int n=weights.size();
    int days=1;
    int load=0;
    for(int i=0;i<n;i++){
        if(load+weights[i] > d){
            days=days+1;
            load=weights[i];
        }
        else{
            load +=weights[i];
        }
    }
    return days; 
}
int leastWeightCapacity(vector<int> &weights,int d){
    int maxi=*max_element(weights.begin(),weights.end());
    int sum=accumulate(weights.begin(),weights.end(),0);
    for(int i=maxi;i<=sum;i++){
        if(find_days(weights,i) <= d){
           return i;
        }
    }
    return -1;
}    
int main(){
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
*/
//OPTIMAL
int find_days(vector<int> &weights,int d){
    int days=1;
    int load=0;
    int n=weights.size();
    for(int i=0;i<n;i++){
        if(load+weights[i] > d){
            days=days+1;
            load=weights[i];
        }
        else{
            load +=weights[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &weights,int d){
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int no0fDays=find_days(weights,mid);
        if(no0fDays<=d){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return low;
}
int main(){
    vector<int> weights={5, 4, 5, 2, 3, 4, 5, 6};
    int d=5;
    int ans=leastWeightCapacity(weights,d);
    cout<<"the least weight transfer capacity of the ship"<<ans;
    return 0;
}