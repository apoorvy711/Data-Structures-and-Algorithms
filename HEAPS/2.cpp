#include<bits/stdc++.h>
using namespace std;

//Kth SMALLEST ELEMENT
class KSMALL{
    public:
    int kthsmall(vector<int>&heap,int k){
        priority_queue<int>pq;
        int n=heap.size();
        for(int i=0;i<k;i++){
            pq.push(heap[i]);
        }

        for(int i=k;i<n;i++){
            if(heap[i]<pq.top()){
                pq.pop();
                pq.push(heap[i]);
            }
        }
        int bs=pq.top();
        return bs;
    }
};

//IS CBT A HEAP
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data):val(data),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    bool isHEAP(TreeNode* root){
        int n=countNODES(root);
        return CBT(root,0,n) && MAXHEAP(root);
    }

    int countNODES(TreeNode* &root){
        if(!root) return 0;
        return 1+countNODES(root->left)+countNODES(root->right);
    }

    bool CBT(TreeNode* &root,int i,int n){
        if(!root) return true;
        if(i>=n){
            return false;
        }
        return CBT(root->left,2*i+1,n) && CBT(root->right,2*i+2,n);
    }

    bool MAXHEAP(  TreeNode* &root ){
        if(!root->left && !root->right) return true;
        if(!root->right){
            return root->val >root->left->val && MAXHEAP(root->left);
        }
        else{
            return (root->val >root->left->val && root->val >root->right->val) && MAXHEAP(root->left) && MAXHEAP(root->right);
        }
    }
};

//MERGE TWO HEAPS
void heapify(vector<int>&ans,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && ans[left]>ans[largest]) largest=left;
    if(right<n && ans[right]>ans[largest]) largest=right;

    if(largest!=i){
        swap(ans[i],ans[largest]);
        heapify(ans,n,largest);
    }

}

vector<int>merge_heaps(vector<int>&heap1,vector<int>&heap2){
    vector<int>ans;
    for(auto & it:heap1){
        ans.push_back(it);
    }
    for(auto & it:heap2){
        ans.push_back(it);
    }
    int n=ans.size();
    for(int i=n/2 -1;i>=0;i--){
        heapify(ans,n,i);
    }
    return ans;
}

//MIN COST OF ROPE
int minCOST(vector<int>&rope){
    priority_queue<int,vector<int>,greater<int>>minHEAP;

    for(auto &it :rope){
        minHEAP.push(it);
    }
    int totalcost=0;
    while(minHEAP.size()>1){
        int first=minHEAP.top();
        minHEAP.pop();
        int second=minHEAP.top();
        minHEAP.pop();
        int cost=first+second;
        totalcost+=cost;
        minHEAP.push(cost);
    }
    return totalcost;
}

//BST TO MINHEAP
struct Treenode{
    int data;
    Treenode*left;
    Treenode*right;
    Treenode(int val):data(val),left(nullptr),right(nullptr){}
};

void inorder(Treenode* root, vector<int>& inorderList) {
    if (!root) return;
    inorder(root->left, inorderList);
    inorderList.push_back(root->data);
    inorder(root->right, inorderList);
}

// Step 2: Fill tree in level order using sorted inorder array
void convertToMinHeap(Treenode* root, vector<int>& inorderList) {
    if (!root) return;

    queue<Treenode*> q;
    q.push(root);

    int index = 0;
    while (!q.empty()) {
        Treenode* current = q.front(); q.pop();
        current->data = inorderList[index++];

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// Driver function
void BST_to_MinHeap(Treenode* root) {
    vector<int> inorderList;
    inorder(root, inorderList);
    convertToMinHeap(root, inorderList);  // fill using level order
}

// Preorder print (to verify Min-Heap)
void print_preorder(Treenode* root) {
    if (!root) return;
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

// Level-order print (optional)
void print_level_order(Treenode* root) {
    queue<Treenode*> q;
    q.push(root);
    while (!q.empty()) {
        Treenode* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

int main(){
    /*
//Kth SMALLEST ELEMENT
    KSMALL A;
    vector<int>heap={7,10,4,20,15};
    int k=4;
    cout<<"the kth smallest element is " <<A.kthsmall(heap,k);

//IS CBT A HEAP  
    TreeNode* root=new TreeNode(40);
    root->left=new TreeNode(30);
    root->right=new TreeNode(35);
    root->left->left=new TreeNode(10);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(20);
    Solution solution;
    bool ans=solution.isHEAP(root);
    if(ans){
        cout<<"CBT IS HEAP";
    }
    else{
        cout<<"CBT IS NOT A HEAP";
    }
    
   vector<int>heap1={40,30,25};
   vector<int>heap2={35,20,10};
   vector<int>ans=merge_heaps(heap1,heap2);
   cout<<"THE NEW HEAP IS"<<endl;
   for(auto &it:ans){
    cout<<it<<" ";
   }
   cout<<endl;
   

//MIN COST OF ROPE
   vector<int>rope={4,3,2,6};
   int ans=minCOST(rope);
   cout<<"the min cost of the rope is"<<ans;
   */
//BST TO MINHEAP
   Treenode* root = new Treenode(4);
    root->left = new Treenode(2);
    root->right = new Treenode(6);
    root->left->left = new Treenode(1);
    root->left->right = new Treenode(3);
    root->right->left = new Treenode(5);
    root->right->right = new Treenode(7);

    cout << "Original BST (Level Order): ";
    print_level_order(root);

    BST_to_MinHeap(root);

    cout << "Min-Heap with left < right subtree condition (Preorder): ";
    print_preorder(root);
    cout << endl;
   

   return 0;
}