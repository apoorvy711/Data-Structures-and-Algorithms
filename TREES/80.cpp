#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode():val(0),left(nullptr),right(nullptr){}

    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
    
    TreeNode(int data,TreeNode*left,TreeNode*right):val(data),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    vector<vector<int>>levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left != nullptr){
                    q.push(node-> left);
                }
                if(node->right != nullptr){
                    q.push(node-> right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    Solution solution;
    vector<vector<int>> result= solution.levelOrder(root);
    cout<<"the level order traversal is";
    for(vector<int>level:result){
        for(int val:level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}