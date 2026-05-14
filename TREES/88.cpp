#include<bits/stdc++.h>
using namespace std;
/*
//BRUTE
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    int diameter=0;
    int calc_Diameter(TreeNode*root){
        if(root==nullptr) return 0;
        int lh=calc_Diameter(root->left);
        int rh=calc_Diameter(root->right);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
    int diameter_binary_trees(TreeNode*root){
        calc_Diameter(root);
        return diameter;
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

    int result=solution.diameter_binary_trees(root);
    cout<<"the diameter of th binary tree is "<<result;

    cout<<endl;
    return 0;
}
*/
//OPTIMAL
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    int diameter_binary_trees(TreeNode* root){
        int diameter=0;
        calc_Diameter(root,diameter);
        return diameter;
    }
    int calc_Diameter(TreeNode*root, int &diameter){
        if(!root) return 0;
        int lh=calc_Diameter(root->left,diameter);
        int rh=calc_Diameter(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
};

int main(){
    TreeNode*root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(7);
    root->right->left=new TreeNode(6);
    

    Solution solution;

    int result=solution.diameter_binary_trees(root);
    cout<<"the diameter of th binary tree is "<<result;

    cout<<endl;
    return 0;
}