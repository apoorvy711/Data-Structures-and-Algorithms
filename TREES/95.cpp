#include<bits/stdc++.h>
using namespace std;

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }

    TreeNode(int data,TreeNode* left1,TreeNode*right1){
        val=data;
        left=left1;
        right=right1;
    }
     
};
/*
class Solution{
    public:
    vector<int>bottom_view(TreeNode* root){
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* Node=it.first;
            int Line=it.second;
            mpp[Line]=Node->val;

            if(Node->left !=NULL){
                q.push({Node->left,Line-1});
            }
            if(Node->right !=NULL){
                q.push({Node->right,Line+1});
            }   
        }
        for(auto &it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
*/

class Solution{
    public:
    vector<int>bottom_view(TreeNode* root){
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int line=it.second;
            mpp[line]=node->val;
            if(node->left != nullptr){
                q.push({node->left,line-1});
            }
            if(node->right != nullptr){
                q.push({node->right,line+1});
            }
        }   
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->left->right->left=new TreeNode(8);
    root->right->left->right=new TreeNode(9);
    

    Solution solution;
    vector<int>ans=solution.bottom_view(root);
    for(auto &it:ans){
        cout<<it<<" ";
    }
    return 0;

}