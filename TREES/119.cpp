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
    TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return NULL;
        int cur=root->data;
        if(cur<p->data && cur< q->data) return LCA(root->right,p,q);
        if(cur>p->data && cur> q->data) return LCA(root->left,p,q);
        return root;
    }
};

void print_tree(TreeNode* root){
    if (!root) return;
    print_tree(root->left);
    cout<<root->data<<" ";
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
    TreeNode* p= root->left->left->left; //2
    TreeNode* q= root->left->left->right;  //4
    TreeNode* ans=solution.LCA(root,p,q);
    cout<<"the lca of p and q is"<<ans->data<<endl;
    return 0;
}