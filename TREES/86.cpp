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
      int maxDepth(TreeNode* root){
            if(root == nullptr){
                return 0;
            }

            int lh=maxDepth(root->left);

            int rh=maxDepth(root->right);

            return 1+max(lh,rh);
      }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->right=new TreeNode(6);
    root->left->right->right->right=new TreeNode(7);

    Solution solution;
    int ans=solution.maxDepth(root);

    cout<<"the maxdepth of the binary tree is "<<ans;
    cout<<endl;
    return 0;

}