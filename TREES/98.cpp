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

    bool getPATH(TreeNode* root,int node, vector<int>&arr){
        if(!root) return false;

        arr.push_back(root->val);

        if(root->val==node){
            return true;
        }

        if(getPATH(root->left,node,arr) || getPATH(root->right,node,arr) ){
            return true;
        }

        arr.pop_back();
        return false;
    }

    vector<int>rootTOnode(TreeNode* root,int node){
        vector<int>arr;
        if(root==NULL){
            return arr;
        }
        getPATH(root,node,arr);
        return arr;
    }
};
*/
class Solution{
    public:

    bool getpath(TreeNode* root, int node,vector<int>&ans){
        if(!root) return false;
        ans.push_back(root->val);
        if(root->val == node) return true;
        if(getpath(root->left,node,ans) || getpath(root->right,node,ans)) return true;
        ans.pop_back();
        return false;
    }

    vector<int>rootTOnode(TreeNode* root, int node){
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        getpath(root,node,ans);
        return ans;
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->left=new TreeNode(6);
    root->left->right->right=new TreeNode(7);
    int node=7;
    Solution solution;
    vector<int>ans=solution.rootTOnode(root,node);
    for(auto &it : ans){
        cout<<it<<" ";
    }
    return 0;
     
}