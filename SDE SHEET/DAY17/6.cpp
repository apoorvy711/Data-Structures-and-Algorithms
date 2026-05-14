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

    TreeNode(int data1,TreeNode* left1, TreeNode* right1){
        val=data1;
        left=left1;
        right=right1;
    }
};

class Solution{
    public:

    void func(TreeNode* node,int level,vector<int>&result){
        if(node==NULL) return;
        if(result.size()==level) result.push_back(node->val);
        func(node->left,level+1,result);
        func(node->right,level+1,result);
    }

    vector<int>left_view(TreeNode* root){
        vector<int>result;
        func(root,0,result);
        return result;
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
    vector<int>ans=solution.left_view(root);
    for(auto &it:ans){
        cout<<it<<" ";
    }
    return 0;
}

