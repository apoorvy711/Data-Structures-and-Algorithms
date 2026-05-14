#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }

    TreeNode(int data,TreeNode* left1,TreeNode*right1){
        val=data;
        left=left1;
        right=right1;
    }

};

class Solution{
    public:
    int count_nodes(TreeNode* root){

        if(root==NULL) return 0;
        int lh=findLEFTheight(root);
        int rh=findRIGHTheight(root);

        if(lh==rh) return (1<<lh)-1;

        return 1+count_nodes(root->left)+count_nodes(root->right);
    }

    int findLEFTheight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }

    int findRIGHTheight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->left->left->left=new TreeNode(8);
    root->left->left->right=new TreeNode(9);
    root->left->right->left=new TreeNode(10);
    root->left->right->right=new TreeNode(11);

    Solution solution;

    int ans=solution.count_nodes(root);
    cout<<"the total nodes are "<<ans;
    return 0;
}