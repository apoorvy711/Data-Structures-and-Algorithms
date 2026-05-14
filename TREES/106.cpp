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
    TreeNode* buildTREE( vector<int>&preorder, vector<int>&inorder){
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build_subtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }

    TreeNode* build_subtree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&mpp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* node=new TreeNode(preorder[preStart]);
        int inRoot=mpp[node->data];
        int numsleft=inRoot-inStart;
        node->left=build_subtree(preorder,preStart+1,preStart+numsleft,inorder,inStart,inRoot-1,mpp);
        node->right=build_subtree(preorder,preStart+numsleft+1,preEnd,inorder,inRoot+1,preEnd,mpp);  
        return node;
    }
};

void printVector(vector<int>&vec){
    int n=vec.size();
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void printTREE(TreeNode* ans){
    TreeNode* node=ans;
    queue<TreeNode*>q;
    q.push(node);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            TreeNode* root=q.front();
            q.pop();
            cout<<root->data<<" ";
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        cout<<endl;
    }
}

int main(){
    vector<int>preorder={3, 9, 20, 15, 7};
    vector<int>inorder={9, 3, 15, 20, 7};
    cout<<"THE PREORDER  IS ";
    printVector(preorder);
    cout<<endl;
    cout<<"THE INORDER  IS ";
    printVector(inorder);
    cout<<endl;

    Solution solution;
    TreeNode* ans=solution.buildTREE(preorder,inorder);
    cout<<"THE BINARY TREE IS";
    printTREE(ans);
    cout<<endl;
    return 0;
}
