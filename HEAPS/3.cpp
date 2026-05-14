#include<bits/stdc++.h>
using namespace std;

//Ktth LARGEST SUM SUBARRAY
int KTHlargest(vector<int>&arr,int k){
    priority_queue<int,vector<int>,greater<int>>mini;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];

            if(mini.size()<k){
                mini.push(sum);
            }
            else if(sum>mini.top()){
                mini.pop();
                mini.push(sum);
            }
        }
    }
    return mini.top();
}

//MERGE K SORTED ARRAYS
vector<int>mergeKSORTEDARRAYS(vector<vector<int>>&ARR){
    using node=pair<int,pair<int,int>>;
    vector<int>RES;
    priority_queue<node,vector<node>,greater<node>>mini;
    int n=ARR.size();
    for(int i=0;i<n;i++){
        if(!ARR[i].empty()){
            mini.push({ARR[i][0],{i,0}});
        }  
    }
    while(!mini.empty()){
        auto topEL=mini.top();
        mini.pop();
        int val=topEL.first;
        int arrind=topEL.second.first;
        int eleind=topEL.second.second;
        RES.push_back(val);
         
        if(eleind +1<ARR[arrind].size()){
            mini.push({ARR[arrind][eleind],{arrind,eleind+1}});
        }
    }
    return RES;
}

//MERGE K SORTED LISTS
struct TreeNode{
    int data;
    TreeNode* next;
    TreeNode* right;
    TreeNode(int val){
        data=val;
        next=nullptr;
        right=nullptr;
    }
};

TreeNode* convertARRtoLL(vector<int>vals){
    TreeNode* head=new TreeNode(vals[0]);
    TreeNode* mover=head;

    for(int i=1;i<vals.size();i++){
        TreeNode* temp=new TreeNode(vals[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void printlist(TreeNode* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

TreeNode* mergeTWOsortedlists(TreeNode* L1,TreeNode*L2){
    if(!L1) return L2;
    if(!L2) return L1;

    if(L1->data <=L2->data){
        L1->next=mergeTWOsortedlists(L1->next,L2);
        return L1;
    }
    else{
        L2->next=mergeTWOsortedlists(L1,L2->next);
        return L2;
    }
}

TreeNode* partitionandmerge(int start,int end,vector<TreeNode*>&lists){
    if(start==end){
        return lists[start];
    }

    if(start>end){
        return nullptr;
    }
    int mid=start+(end-start)/2;

    TreeNode* L1=partitionandmerge(start,mid,lists);
    TreeNode* L2=partitionandmerge(mid+1,end,lists);

    return mergeTWOsortedlists(L1,L2);
}

TreeNode* mergeKlists(vector<TreeNode*>&lists){
    int n=lists.size();
    if(n==0) return nullptr;

    return partitionandmerge(0,n-1,lists);
}

int main(){
//Ktth LARGEST SUM SUBARRAY   
    vector<int>arr={10,-10,20,-40};
    int k=6;
    int ans=KTHlargest(arr,k);
    cout<<"the answer is"<<ans;

//MERGE K SORTED ARRAYS
    vector<vector<int>>ARR= {{1,4,5},
                     {1,3,4},
                     {2,6 }};
    vector<int>ANS=mergeKSORTEDARRAYS(ARR);
    cout<<"the sorted array is:";
    for(auto &it:ANS){
        cout<<it<<" ";
    }   
//MERGE K SORTED LISTS
    TreeNode* L1 = convertARRtoLL({1, 4, 5});
    TreeNode* L2 = convertARRtoLL({1, 3, 4});
    TreeNode* L3 = convertARRtoLL({2, 6});
    vector<TreeNode*> lists = {L1, L2, L3};
    TreeNode* merged=mergeKlists(lists);
    cout << "Merged Sorted Linked List: ";
    printlist(merged);
    return 0;                 
}
