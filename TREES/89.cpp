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

    int cal_maxsum(TreeNode*root,int &maxi){
        if(root==nullptr) return 0;
        int lh_sum=max(0,cal_maxsum(root->left,maxi));
        int rh_sum=max(0,cal_maxsum(root->right,maxi));
        maxi=max(maxi,lh_sum+rh_sum+root->val);
        return (root->val)+max(lh_sum,rh_sum);
    }

    int max_path(TreeNode*root){
        int maxi=INT_MIN;
        cal_maxsum(root,maxi);
        return maxi;
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

    int result=solution.max_path(root);
    cout<<"the maximum path of the binary tree is "<<result;

    cout<<endl;
    return 0;
}