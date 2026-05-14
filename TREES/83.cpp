#include<bits/stdc++.h>
using namespace std;
/*
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right; 
    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    vector<int> postOrder(TreeNode* root){
        vector<int> postorder;

        if(root==nullptr) return postorder;
        stack<TreeNode*> st1,st2;

        st1.push(root);

        while(!st1.empty()){
            TreeNode* node=st1.top();
            st1.pop();

            st2.push(node);

            if(node->left){
                st1.push(node->left);
            }
            if(node->right){
                st1.push(node->right);
            }
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):val(data),left(nullptr),right(nullptr){};
};

class Solution{
    public:
    vector<int>postOrder(TreeNode* root){
        vector<int>level;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        while(!st2.empty()){
            level.push_back(st2.top()->val);
            st2.pop();
        }
        return level;
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    Solution solution;
    vector<int> result=solution.postOrder(root);
    cout<<"the preorder traversal is ";
    for(int val: result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}