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
    bool isIdentical(TreeNode*root1,TreeNode*root2){

        if(root1==nullptr && root2==nullptr){
            return true;
        }
        if(root1==nullptr || root2==nullptr){
            return false;
        }
        return((root1->val == root2->val) && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right));
    }
};

int main(){
    TreeNode* root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    root1->left->left=new TreeNode(4);

    TreeNode* root2=new TreeNode(1);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);
    root2->left->left=new TreeNode(4);

    Solution solution;
    if(solution.isIdentical(root1,root2)){
        cout<<"the trees are identical "<<endl;
    }
    else {
        cout<<"the trees are not identical "<<endl;
    }
    return 0;
}