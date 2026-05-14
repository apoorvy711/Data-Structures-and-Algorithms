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

class Solution{
    public:

    bool isSYM(TreeNode* root){
        return root==NULL || isSYMHelp(root->left,root->right);
    }

    bool isSYMHelp(TreeNode* left,TreeNode*right){
        if(left==NULL || right==NULL){
            return left==right;
        }
        if(left->val !=right->val) return false;
        return isSYMHelp(left->left,right->right) && isSYMHelp(left->right,right->left);
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->right->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    Solution solution;
    bool ans=solution.isSYM(root);
    if(ans){
        cout<<"the BT is symmetrical";
    }
    else{
        cout<<"the BT is not symmetrical";
    }
    return 0;
}