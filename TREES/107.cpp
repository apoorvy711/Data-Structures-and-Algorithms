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

    TreeNode* buildTREE( vector<int>&inorder, vector<int>&postorder){
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build_subtree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }

    TreeNode* build_subtree(vector<int>&inorder,int inStart,int inEnd,vector<int>&postorder,int postStart,int postEnd,map<int,int>&mpp){
        if(postStart > postEnd || inStart > inEnd) return NULL;
        TreeNode* node=new TreeNode(postorder[postEnd]);
        int inRoot=mpp[node->data];
        int numsleft=inRoot-inStart;
        node->left=build_subtree(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsleft-1,mpp);
        node->right=build_subtree(inorder,inRoot+1,inEnd,postorder,postStart+numsleft,postEnd-1,mpp);
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
    vector<int>postorder={9 ,15 ,7 ,20, 3};
    vector<int>inorder={9, 3, 15, 20, 7};
    cout<<"THE POSTORDER  IS ";
    printVector(postorder);
    cout<<endl;
    cout<<"THE INORDER  IS ";
    printVector(inorder);
    cout<<endl;

    Solution solution;
    TreeNode* ans=solution.buildTREE(inorder,postorder);
    cout<<"THE BINARY TREE IS"<<endl;
    printTREE(ans);
    cout<<endl;
    return 0;
}
