/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void postOrder(TreeNode* A, vector<int> &ret){
    if(A==NULL) return;
    postOrder(A->left,ret);
    postOrder(A->right,ret);
    ret.push_back(A->val);
    return;
} 
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ret;
    postOrder(A,ret);
    return ret;
}
