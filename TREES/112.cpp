#include<bits/stdc++.h>
using namespace std;

struct  TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }

    TreeNode(int data,TreeNode* left1,TreeNode* right1){
        val=data;
        left=left1;
        right=right1;
    }

};

class Solution{
    public:
    TreeNode* search_node(TreeNode* root,int num){
        while(root !=NULL && root->val !=num){
            root=num<root->val?root->left:root->right;
        }
        return root;
    }
};

int main(){

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    Solution solution;

    int num=18;

    TreeNode* ans=solution.search_node(root,num); 
    if(!ans){
        cout<<"the node is not present";
    }
    else{
        cout<<"the node is present";
    }
    cout<<endl;
    return 0;
}