#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
    TreeNode(int data,TreeNode* left1,TreeNode* right1):val(data),left(left1),right(right1){}
};

int maxTimeTaken(TreeNode* target,unordered_map<TreeNode*,TreeNode*>&parent){
    unordered_map<TreeNode*,int>visited;
    queue<TreeNode*>q;
    q.push(target);
    visited[target]=1;
    int maxi=0;
    while(!q.empty()){
        int size=q.size();
        int flag=0;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                flag=1;
                visited[node->left]=1;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]){
                flag=1;
                visited[node->right]=1;
                q.push(node->right);
            }
            if(parent[node] && !visited[parent[node]]){
                flag=1;
                visited[parent[node]]=1;
                q.push(parent[node]);
            }
        }
        if(flag) maxi++;
    }
    return maxi;
}

TreeNode*bfs_parentNodeMarking(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent ,int start){
    queue<TreeNode*>q;
    q.push(root);
    TreeNode* res=nullptr;
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->val==start) res=node;
        if(node->left){
            parent[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parent[node->right]=node;
            q.push(node->right);
        }
    }
    return res;
}

int minTimetoBurn_TREE(TreeNode* root, int start){
    unordered_map<TreeNode*,TreeNode*>parent;
    TreeNode* target=bfs_parentNodeMarking(root,parent,start);
    return maxTimeTaken(target,parent);
}

void printTree(TreeNode* root){
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
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(6);
    root->right->left=new TreeNode(5);
    root->left->left->right=new TreeNode(7);
    printTree(root);
    int start=2;
    int ans=minTimetoBurn_TREE(root,start);
    cout<<ans;
    return 0;

}