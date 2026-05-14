#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
    TreeNode(int data,TreeNode* left1,TreeNode* right1):val(data),left(left1),right(right1){}
};

int maxWidth_in_TREE(TreeNode* root){
    if(!root) return 0;
    TreeNode* ans=root;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    int res=0;
    while(!q.empty()){
        TreeNode* node=q.front().first;
        int size=q.size();
        int min_pt=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int cur_id=q.front().second - min_pt;
            TreeNode* node=q.front().first;
            q.pop();
            if(i==0) first=cur_id;
            if(i==size-1) last=cur_id;
            if(node->left){
                q.push({node->left,2*cur_id+1});
            }
            if(node->right){
                q.push({node->right,2*cur_id+2});
            }
        }
        res=max(res,last-first+1);
    }
    return res;
}

void printTree(TreeNode * root){
    TreeNode * node=root;
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            TreeNode * ans=q.front();
            q.pop();
            cout<<ans->val<<" ";
            if(ans->left) q.push(ans->left);
            if(ans->right) q.push(ans->right);
        }
        cout<<endl;
    }
}

int main(){
    TreeNode * root= new TreeNode(1);
    root->left=new TreeNode(7);
    root->right=new TreeNode(10);
    root->left->left=new TreeNode(9);
    root->left->right=new TreeNode(2);
    root->right->right=new TreeNode(7);
    root->right->left=new TreeNode(2);
    root->left->left->left=new TreeNode(11);
    root->left->left->right=new TreeNode(10);
    root->left->right->right=new TreeNode(6);
    root->left->right->left=new TreeNode(9);
    root->right->left->left=new TreeNode(1);
    root->right->left->right=new TreeNode(7);
    root->right->right->right=new TreeNode(10);
    root->right->right->left=new TreeNode(6);
    printTree(root);
    int ans=maxWidth_in_TREE(root);
    cout<<ans;
    return 0;

}

