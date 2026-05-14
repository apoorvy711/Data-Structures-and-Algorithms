#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    vector<vector<int>> zigzaglevel(TreeNode*root){
        vector<vector<int>> result;
        if(root==nullptr){
            return result;
        }

        queue<TreeNode*>queueNodes;
        queueNodes.push(root);

        bool LeftToRight=true;

        while(!queueNodes.empty()){
            int size=queueNodes.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                TreeNode* root=queueNodes.front();
                queueNodes.pop();
                int index=(LeftToRight)? i : (size-1-i);

                row[index]=root->val;
                if(root->left){
                    queueNodes.push(root->left);
                }
                if(root->right){
                    queueNodes.push(root->right);
                }
            }
            LeftToRight = !LeftToRight;
            result.push_back(row);
        }
        return result;
    } 

};

int main(){
    TreeNode*root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->right=new TreeNode(6);
    root->left->right->right->right=new TreeNode(7); 

    Solution solution;

    vector<vector<int>> result=solution.zigzaglevel(root);
    cout<<"the maximum path of the binary tree is ";
    for(auto it:result){
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}