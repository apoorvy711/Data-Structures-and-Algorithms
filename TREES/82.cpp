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
    vector<int> inOrder(TreeNode* root){
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node=root;

        while(true){
            if(node !=nullptr) {
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
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
    vector<int>inOrder(TreeNode* root){
        vector<int>level;
        stack<TreeNode*>st;
        TreeNode* node=root;
        while(node != NULL || !st.empty()){
            if(node !=nullptr){
                st.push(node);
                
                node=node->left;
            }
            else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                level.push_back(node->val);
                node=node->right;
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
    vector<int> result=solution.inOrder(root);
    cout<<"the preorder traversal is ";
    for(int val: result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}