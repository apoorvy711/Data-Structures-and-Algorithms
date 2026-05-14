#include<bits/stdc++.h>
using namespace std;
/**/
//Aggressive Cows 
//BRUTE
bool cows_we_place(vector<int> &stalls,int dist,int totalCows){
    int cntCows=1;
    int last=stalls[0];
    int n=stalls.size();
    
    for(int i=0;i<n;i++){
        if(stalls[i]-last >= dist){
            cntCows++;
            last=stalls[i];
        }
        if(cntCows >= totalCows) return true;
    }
    return false;
}
int Aggressive_cows(vector<int> &stalls,int totalCows){
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int limits=stalls[n-1]-stalls[0]; 
    int ans=0; 
    for(int i=0;i<limits;i++){
        if(cows_we_place(stalls,i,totalCows)){
            ans=i;
        }
    }
    return ans;
}
int main(){
    vector<int> stalls={0, 3, 4, 7, 10, 9};
    int totalCows=4;
    int ans=Aggressive_cows(stalls,totalCows);
    cout<<"the maximum possible minimum distance is "<<ans;
    return 0;
}

//OPTIMAL
bool can_we_place(vector<int> &stalls,int dist,int totalCows){
    int n=stalls.size();
    int cntCows=1;
    int last=stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]-last>=dist){
            cntCows++;
            last=stalls[i];
        }
        if(cntCows >= totalCows) return true;
    }
    return false;
}
int Aggressive_cows(vector<int> &stalls,int totalCows){
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[n-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(can_we_place(stalls,mid,totalCows)==true){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
int main(){
    vector<int> stalls={0, 3, 4, 7, 10, 9};
    int totalCows=4;
    int ans=Aggressive_cows(stalls,totalCows);
    cout<<"the maximum possible minimum distance is "<<ans;
    return 0;
}