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
    bool ifLeaf(TreeNode* root){
        return (!root->left && !root->right);
    }
    void leftboundary(TreeNode* root,vector<int>&result){
        TreeNode* current = root->left;
        while(current){
            if(!ifLeaf(current)){
                result.push_back(current->val);
            }
            if(current ->left){
                current=current->left;
            }
            else{
                current=current->right;
            }
        }
    }
    void addLeaves(TreeNode* root, vector<int>&result){
        if(ifLeaf(root)){
            result.push_back(root->val);
            return;
        }
        if(root->left) addLeaves(root->left,result);
        if(root->right) addLeaves(root->right,result); 
    }
    void rightboundary(TreeNode* root, vector<int>&result){
        vector<int>temp;
        TreeNode* current=root ->right;
        while(current){
            if(!ifLeaf(current)){
                temp.push_back(current->val);
            }
            if(current->right){
                current=current->right;
            }
            else{
                current=current->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            result.push_back(temp[i]);
        }

    }
    vector<int>printboundary(TreeNode* root){
        vector<int>result;
        if(root == nullptr) return result;
        if(!ifLeaf(root)){
            result.push_back(root->val);
        }
        leftboundary(root,result);
        addLeaves(root,result);
        rightboundary(root,result);
        return result;
    }
};

/*
class Solution{
    public:

    bool ifLeaf(TreeNode*root){
        return (!root->left && !root->right );
    }

    void addleftboundary(TreeNode*root,vector<int> &result){
        TreeNode* current=root ->left;
        while(current){
            if(!ifLeaf(current)){
                result.push_back(current -> val);
            }
            if(current -> left){
                current=current -> left;
            }
            else{
                current=current -> right;
            }
        }
    }

    void addrightoundary(TreeNode* root,vector<int> &result){
        vector<int> temp;
        TreeNode* current=root ->right;
        while(current){
            if(!ifLeaf(current)){
                temp.push_back(current -> val);
            }
            if(current ->right){
                current=current->right;
            }
            else{
                current=current->left;
            }
        } 
        for(int i=temp.size()-1;i>=0;i--){
            result.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode*root,vector<int> &result){
        if(ifLeaf(root)){
            result.push_back(root -> val);
            return;
        }
        if(root -> left){
            addLeaves(root -> left,result);
        } 
        if(root -> right){
            addLeaves(root -> right,result);
        }
    }

    vector<int> printboundary(TreeNode*root){
        vector<int> result;
        if(root==nullptr) return result;
        if(!ifLeaf(root)){
            result.push_back(root -> val);
        }
        addleftboundary(root,result);
        addLeaves(root,result);
        addrightoundary(root,result);
        return result;
    }  
};
*/
int main(){
    TreeNode* root=new TreeNode(1);
    root -> left=new TreeNode(2);
    root -> right=new TreeNode(3);
    root -> left -> left=new TreeNode(4);
    root -> left -> right=new TreeNode(5);
    root -> right -> left=new TreeNode(6);
    root -> right -> right=new TreeNode(7);
    Solution solution;
    vector<int> results=solution.printboundary(root);
    cout<<"the boundary traversal is";
    for(auto it:results){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}