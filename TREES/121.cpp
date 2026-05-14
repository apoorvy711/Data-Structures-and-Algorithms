#include<bits/stdc++.h>
using namespace std;

struct  TreeNode{
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
    TreeNode* inorder_successor(TreeNode* root,TreeNode* k){
        TreeNode* successor=NULL;
        while(root !=NULL){
            if(root->data>k->data){
                successor=root;
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return successor;
    }
    TreeNode* inorder_predecessor(TreeNode* root,TreeNode* k){
        TreeNode* predecessor=NULL;
        while(root !=NULL){
            if(root->data<k->data){
                predecessor=root;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return predecessor;
    }
}; 

int main(){
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    root->left->right->left=new TreeNode(3);
    root->right->right->left=new TreeNode(8);
    root->right->right->right=new TreeNode(10);
    Solution solution;
    TreeNode* k=root->right->right->left;
    TreeNode* ans=solution.inorder_successor(root,k);
    cout<<ans->data<<" ";
    TreeNode* ANS=solution.inorder_predecessor(root,k);
    cout<<ANS->data<<" ";
    return 0;
}