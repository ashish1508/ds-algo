/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    int cln=1,nln=0,l=0;
    queue<TreeNode*> q;
    vector< vector<int> > ret;
    if(A==NULL) return ret;
    q.push(A);
    while(!q.empty()){
        vector<int> v;
        TreeNode* f = q.front();
        q.pop();
        v.push_back(f->val);
        cln--;
        if(f->left){
            q.push(f->left);
            nln++;
        }
        if(f->right){
            q.push(f->right);
            nln++;
        }
        if(cln==0){
            if(l%2){
                reverse(v.begin(),v.end());
            }
            ret.push_back(v);
            v.clear();
            cln=nln;
            nln=0;
            l++;
        }
    }
    return ret;
}
