#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode*left;
    TreeNode*right; 
    
    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};
/*
class Solution{
    public:
    vector<vector<int>> all_three_traversals(TreeNode*root){
        vector<int> preorder,inorder,postorder;
        if(root==nullptr) return {};
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});

        while(!st.empty()){
            auto &it=st.top();
            TreeNode* node=it.first;
            int state=it.second;
            st.pop();

            if(state==1){
                preorder.push_back(node->data);
                it.second++;
                st.push(it);
                
                if(node->left){
                    st.push({node->left,1});
                }
            }
            else if(state==2){
                inorder.push_back(node->data);
                it.second++;
                st.push(it);
                
                if(node->right){
                    st.push({node->right,1});
                }
            }
            else{
                postorder.push_back(node->data);
            }
        }
        return {preorder,inorder,postorder};
    }
};
*/

class Solution{
    public:
    vector<vector<int>>all_three_traversals(TreeNode* root){
        vector<int>pre,in,post;
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        while(!st.empty()){
            auto &it=st.top();
            st.pop();
            TreeNode* node=it.first;
            int state=it.second;
            if(state==1){
                pre.push_back(node->data);
                it.second++;
                st.push(it);
                if(node->left){
                    st.push({node->left,1});
                } 
            }
            else if(state==2){
                in.push_back(node->data);
                it.second++;
                st.push(it);
                if(node->right){
                    st.push({node->right,1});
                } 
            }
            else{
                post.push_back(node->data);
            }
        }
        return {pre,in,post};
    }
};
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);

    Solution solution;
    vector<vector<int>> result=solution.all_three_traversals(root);

    vector<int> preorder=result[0];
    vector<int> inorder=result[1];
    vector<int> postorder=result[2];

    cout<<"the preorder traversal is ";
    for(int val:preorder){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"the inorder traversal is ";
    for(int val:inorder){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"the postorder traversal is ";
    for(int val:postorder){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}