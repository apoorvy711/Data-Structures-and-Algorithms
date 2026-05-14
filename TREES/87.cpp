#include<bits/stdc++.h>
using namespace std;

//BRUTE
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
};

class Solution{
    public:

    bool isBalanced(TreeNode *root){
        if(root==nullptr){
            return true;
        }
        int lh=dfsheight(root->left);
        int rh=dfsheight(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }

        return false;
    }

    int dfsheight(TreeNode* root){

        if(root==nullptr) return 0;

        int lh=dfsheight(root->left);
        int rh=dfsheight(root->right);

        return max(lh,rh)+1;
    }
  
    
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right =new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(7);

    Solution solution;

    if(solution.isBalanced(root)){
        cout<<"the binary tree is balanced";
    }
    else{
        cout<<"the binary tree is not balanced";  
    } 
    return 0;
}

//OPTIMAL
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    bool isBalanced(TreeNode* root){
        return dfsheight(root) !=-1;
    }
    int dfsheight(TreeNode*root){
        if(root==nullptr) return 0;

        int lh=dfsheight(root->left);
        if(lh==-1) return -1;

        int rh=dfsheight(root->right);
        if(rh==-1) return -1;

        if(abs(lh-rh) > 1){
            return -1;
        }
        return max(lh,rh)+1;
    }

    /*
    int check(TreeNode*  root){
        if(root==nullptr) return 0;
        int lh=check(root->left);
        if(lh==-1) return -1;
        int rh=check(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh) >1) return -1;
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode*  root){
        return check(root) !=-1;
    }
    */
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right =new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(7);

    Solution solution;

    if(solution.isBalanced(root)){
        cout<<"the binary tree is balanced";
    }
    else{
        cout<<"the binary tree is not balanced";  
    } 
    return 0;
}
