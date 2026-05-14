#include<bits/stdc++.h>
using namespace std;

//Smallest Range Covering Elements from K Lists
vector<int>smallestRange(vector<vector<int>>&nums){
    using node=pair<int,pair<int,int>>;
    priority_queue<node,vector<node>,greater<node>> minheap;
    int start=0;
    int end=INT_MAX;
    int maxi=INT_MIN;

    for(int i=0;i<nums.size();i++){
        int val=nums[i][0];
        minheap.push({val,{i,0}});
        maxi=max(maxi,val);
    }

    while(minheap.size()==nums.size()){
        auto top=minheap.top();
        minheap.pop();

        int mini=top.first;
        int row=top.second.first;
        int col=top.second.second;

        if(maxi-mini < end-start){
            start=mini;
            end=maxi;
        }

        if( col+1 < nums[row].size()){
            int nextval=nums[row][col+1];
            minheap.push({nextval,{row,col+1}});
            maxi=max(maxi,nextval);
        }
    }
    return {start,end};
}

//FIND MEDIAN FROM DATA STREAM
priority_queue<int>left_max_heap;
priority_queue<int,vector<int>,greater<int>>right_min_heap;
void addnum(int num){

    if(left_max_heap.empty() || num < left_max_heap.top()){
        left_max_heap.push(num);
    }
    else{
        right_min_heap.push(num);
    }

    if(abs((int)left_max_heap.size()-(int)right_min_heap.size()) > 1){
        right_min_heap.push(left_max_heap.top());
        left_max_heap.pop();
    }
    else if(left_max_heap.size() < right_min_heap.size()){
        left_max_heap.push(right_min_heap.top());
        right_min_heap.pop();
    }
} 

double findMedian(){
    if(left_max_heap.size() == right_min_heap.size()){
        double mean=(left_max_heap.top() + right_min_heap.top()) / 2;
        return mean;
    }
    return left_max_heap.top();
}

int main(){
//Smallest Range Covering Elements from K Lists

    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    vector<int> result = smallestRange(nums);
    cout << "Smallest range: [" << result[0] << ", " << result[1] << "]\n";

//FIND MEDIAN FROM DATA STREAM

    int num;
    cout<<"the numbers are";
    while(cin>>num && num!=-1){
        addnum(num);
        cout<<"the median of the numbers is "<<findMedian()<<endl;
    }
    return 0;
}


