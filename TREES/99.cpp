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
    TreeNode* lca(TreeNode* root,TreeNode*a ,TreeNode* b){
        if( root==NULL || root==a || root==b){
            return root;
        }
        TreeNode* left=lca(root->left,a,b);
        TreeNode* right=lca(root->right,a,b);

        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    TreeNode* a=root->left->left;
    TreeNode* b=root->left->right->right;
    Solution solution;
    TreeNode* ans=solution.lca(root,a,b);
    cout<<"the common ancestor is "<<ans->val;
    return 0;

}