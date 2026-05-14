#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>maxCombinations(vector<int>&nums1 , vector<int>&nums2, int k){
        int n=nums1.size();
        sort(nums1.begin(),nums1.end(),greater<int>());
        sort(nums2.begin(),nums2.end(),greater<int>());
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>visited;
        pq.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});
        vector<int>result;
        while(k-- && !pq.empty()){
            auto top=pq.top();
            pq.pop();
            int sum=top.first;
            int i=top.second.first;
            int j=top.second.second;
            result.push_back(sum);
            if( i+1<n && !visited.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                visited.insert({i+1,j});
            }
            if( j+1<n && !visited.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
        }
        return result;
    }
};





int main() {
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    Solution sol;
    vector<int> ans = sol.maxCombinations(nums1, nums2, k);
    cout << "Maximum " << k << " combinations are: ";
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}




