/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void preOrder(TreeNode* A, vector<int> &ret){
    if(A==NULL) return;
    ret.push_back(A->val);
    preOrder(A->left,ret);
    preOrder(A->right,ret);
    return;
} 
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ret;
    preOrder(A,ret);
    return ret;
    
}
