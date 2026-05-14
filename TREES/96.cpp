#include<bits/stdc++.h>
using namespace std;

//RIGHT VIEW
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

class Solution{
    public:

    vector<int>right_view(TreeNode* root){
        vector<int>result;
        func(root,0,result);
        return result;
    }
    
    void func(TreeNode* root,int level,vector<int>&result){
        if(root==NULL) return ;
        if(result.size()==level) result.push_back(root->val);
        func(root->right,level+1,result);
        func(root->left,level+1,result);
    }

};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(7);
    root->left->right->left=new TreeNode(6);


    Solution solution;
    vector<int>ans=solution.right_view(root);
    for(auto &it:ans){
        cout<<it<<" ";
    }
    return 0;

}

//LEFT VIEW
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

class SolutioN{
    public:

    vector<int>left_view(TreeNode* root){
        vector<int>result;
        func(root,0,result);
        return result;
    }
    
    void func(TreeNode* root,int level,vector<int>&result){
        if(root==NULL) return ;
        if(result.size()==level) result.push_back(root->val);
        func(root->left,level+1,result);
        func(root->right,level+1,result);
    }

};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(7);
    root->left->right->left=new TreeNode(6);


    SolutioN solution;
    vector<int>ans=solution.left_view(root);
    for(auto &it:ans){
        cout<<it<<" ";
    }
    return 0;

}

