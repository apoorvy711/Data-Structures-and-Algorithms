#include<bits/stdc++.h>
using namespace std;
/*
//PREORDER
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

void preorder(Node* root, vector<int>&arr){
    if(root==nullptr) return ;
    arr.push_back(root->data);
    preorder(root->left,arr);
    preorder(root->right,arr);
}

vector<int>preOrder(Node* root){
    vector<int>arr;
    preorder(root,arr);
    return arr;
}

int main(){
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    vector<int>result=preOrder(root);
    cout<<"the preorder traversal is :";
    for(int val:result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0; 
}


//INORDER
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

void inorder(Node* root, vector<int>&arr){
    if(root==nullptr) return ;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

vector<int>inOrder(Node* root){
    vector<int>arr;
    inorder(root,arr);
    return arr;
}

int main(){
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    vector<int>result=inOrder(root);
    cout<<"the inorder traversal is :";
    for(int val:result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0; 
}

//INORDER
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

void postorder(Node* root, vector<int>&arr){
    if(root==nullptr) return ;
    postorder(root->left,arr);
    postorder(root->right,arr);
    arr.push_back(root->data);
}

vector<int>postOrder(Node* root){
    vector<int>arr;
    postorder(root,arr);
    return arr;
}

int main(){
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    vector<int>result=postOrder(root);
    cout<<"the postorder traversal is :";
    for(int val:result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0; 
}

//MAXIMUM DEPTH OF TREE
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

int maxD(Node* root){
    if(root==nullptr) return 0;
    int right=maxD(root->right);
    int left=maxD(root->left);
    return 1+max({left,right});
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    int ans=maxD(root);
    cout<<ans;
    return 0;
}

//LEVEL ORDER TRAVERSAL/ BREADTH FIRST SEARCH
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data(0),left(nullptr),right(nullptr){}
    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left, TreeNode* right):data(val),left(nullptr),right(nullptr){}
};

vector<vector<int>>levelOrder(TreeNode* root){
    vector<vector<int>>ans;
    if(root==nullptr) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left !=nullptr){
                q.push(node->left);
            }
            if(node->right !=nullptr){
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    vector<vector<int>> result=levelOrder(root);
    cout<<"the level order traversal is";
    for(auto it:result){
        for(auto x:it){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}    

//IS BALANCED
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};
int dfsheight(TreeNode* root){
    if(root==nullptr) return 0;
    int lh=dfsheight(root->left);
    if(lh==-1) return -1;
    int rh=dfsheight(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1){
        return -1;
    }
    return 1+max(lh,rh);
}
bool isBalanced(TreeNode* root){
    return dfsheight(root) !=-1;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right =new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(7);
    if(isBalanced(root)){
        cout<<"the binary tree is balanced";
    }
    else{
        cout<<"the binary tree is not balanced";  
    } 
    return 0;
}

//VALID BST
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
    TreeNode(int val, TreeNode* left1, TreeNode* right1):data(val),left(left1),right(right1){}
};

bool isValidBST(TreeNode* root, long long mini , long long maxi){
    if(root==nullptr) return true;
    if(root->data >=maxi || root->data <=mini) return false;
    return  isValidBST(root->left,mini,root->data) && isValidBST(root->right,root->data,maxi);
}

bool isValid(TreeNode* root){
    return isValidBST(root,LLONG_MIN,LLONG_MAX);
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    bool ans=isValid(root);
    if(ans==1){
        cout<<"the bst is valid";
    }
    else{
        cout<<"the bst is invalid";
    }
}

//LCA
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

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==nullptr) return nullptr;
    int curr=root->data;
    if(curr>p->data && curr>q->data) return LCA(root->left,p,q);
    if(curr<p->data && curr<q->data) return LCA(root->right,p,q);
    return root;
}

int main(){
    TreeNode* root =new TreeNode(10);
    root->left =new TreeNode(5);
    root->right =new TreeNode(13);
    root->left->left =new TreeNode(3);
    root->left->left->left =new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    TreeNode* p= root->left->left->left; //2
    TreeNode* q= root->left->left->right;  //4
    TreeNode* ans=LCA(root,p,q);
    cout<<"the lca of p and q is"<<ans->data<<endl;
    return 0;
}

//ZIG ZAG LEVEL BST
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};
vector<vector<int>>zigzagLevelOrder(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    bool leftToRight=true;
    vector<vector<int>>ans;
    while(!q.empty()){
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            int index=leftToRight?i:size-i-1;
            level[index]=node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for(auto &level : ans){
        for(auto x : level){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}


*/