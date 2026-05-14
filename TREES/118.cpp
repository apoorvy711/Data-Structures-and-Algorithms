#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }

    TreeNode(int val,TreeNode* left1,TreeNode* right1){
        data=val;
        left=left1;
        right=right1;
    }
};

class Solution{
    public:
    bool isValid(TreeNode* root){
        return isValidBST(root,INT_MIN,INT_MAX);
    }
    bool isValidBST(TreeNode* root,int mini,int maxi){
        if(root==NULL) return true;
        if(root->data >=maxi || root->data <=mini) return false;
        return isValidBST(root->left,mini,root->data) && isValidBST(root->right,root->data,maxi);
    }
};

void print_tree(TreeNode* root){
    if (!root) return;
    print_tree(root->left);
    cout<<root->data;
    print_tree(root->right);
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    Solution solution;
    bool ans=solution.isValid(root);
    if(ans==1){
        cout<<"the bst is valid";
    }
    else{
        cout<<"the bst is invalid";
    }
}