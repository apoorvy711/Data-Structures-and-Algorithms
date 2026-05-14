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
    vector<int> preOrder(TreeNode* root){
        vector<int> preorder;
        if(root==nullptr){
            return preorder;
        }
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            preorder.push_back(root->val);
            if( root->right != nullptr){
                st.push(root->right);
            }
            if(root->left != nullptr ){
                st.push(root->left);
            }
        }
        return preorder;
    }       
};
*/

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int data):val(data),left(nullptr),right(nullptr){};
};

class Solution{
    public:
    vector<int>preOrder(TreeNode * root){
        vector<int>level;
        if(root==nullptr) return level;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            level.push_back(root->val);
            if(root->right!=nullptr){
                st.push(root->right);
            }
            if(root->left!=nullptr){
                st.push(root->left);
            }
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
    vector<int> result=solution.preOrder(root);
    cout<<"the preorder traversal is ";
    for(int val: result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}