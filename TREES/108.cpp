#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }

    TreeNode(int val,TreeNode* left1,TreeNode* right1){
        data=val;
        left=left1;
        right=right1;
    }

};

class Solution{
    public:
    string serialize(TreeNode* root){
        if(!root) return "";
        queue<TreeNode*>q;
        q.push(root);
        string s="";
        while(!q.empty()){
            TreeNode* curNode=q.front();
            q.pop();
            if(curNode==nullptr){
                s+="#,";
            }
            else{
                s += to_string(curNode->data)+",";
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data){
        if(data.empty()) return NULL;
        queue<TreeNode*>q;
        stringstream s(data);
        string str="";
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str !="#"){
                TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str !="#"){
                TreeNode* rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

void printTREE(TreeNode* ans){
    TreeNode* node=ans;
    queue<TreeNode*>q;
    q.push(node);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            TreeNode* root=q.front();
            q.pop();
            cout<<root->data<<" ";
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        cout<<endl;
    }
}

int main(){ 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout<<"the original tree is"<<endl;
    printTREE(root);
  

    Solution solution;
    
    string serialized=solution.serialize(root);
    cout<<"SERIALIZED STRING IS "<<serialized<<" "<<endl;

    TreeNode* deserialized=solution.deserialize(serialized);
    cout<<"THE TREE IS "<<endl;
    printTREE(deserialized);
    cout<<endl;
    return 0;


}