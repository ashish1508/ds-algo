/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    int cln=1,nln=0;
    vector<int> ret;
    if(A==NULL) return ret;
    queue<TreeNode* > q;
    q.push(A);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        cln--;
        if(t->left){
            q.push(t->left);
            nln++;
        }
        if(t->right){
            q.push(t->right);
            nln++;
        }
        if(cln==0){
            ret.push_back(t->val);
            cln = nln;
            nln=0;
        }
    }
    return ret;
}
