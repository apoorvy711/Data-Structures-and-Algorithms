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
    TreeNode* BSTfromPreorder(vector<int>&A){
        int i=0;
        return build(A,i,INT_MAX);
    }
    TreeNode* build(vector<int>&A,int &i,int bound){
        if(i==A.size() || A[i]> bound) return NULL;
        TreeNode* root=new TreeNode(A[i++]);
        root->left=build(A,i,root->data);
        root->right=build(A,i,bound);
        return root;
    }

};

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
    vector<int>A={8,5,1,7,10,12};
    Solution solution;
    TreeNode* ans=solution.BSTfromPreorder(A);
    printTREE(ans);
    return 0;
}

