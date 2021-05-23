/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inOrder(TreeNode* A, vector<int> &ret){
    if(A==NULL) return;
    inOrder(A->left,ret);
    ret.push_back(A->val);
    inOrder(A->right,ret);
    return;
} 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ret;
    inOrder(A,ret);
    return ret;
}
