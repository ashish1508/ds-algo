/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void getvals(TreeNode* A, int &maxi, int &mini,int i){
    if(A==NULL) return;
    if(i<mini) mini = i;
    if(i>maxi) maxi = i;
    if(A->left) {
        getvals(A->left,maxi,mini,i-1);
    }
    if(A->right) {
        getvals(A->right,maxi,mini,i+1);
    }
    return;
} 
void levelOrder(TreeNode* A, vector<vector<int> > &diag, int i,int mini){
    if(A==NULL) return;
    queue< pair<TreeNode*, int> > q;
    pair<TreeNode*,int> f; 
    q.push({A,0});
    while(!q.empty()){
        f = q.front();
        q.pop();
        TreeNode* t = f.first;
        diag[f.second-mini].push_back(t->val);
        if(t->left)
            q.push({t->left,f.second-1});
        if(t->right)
            q.push({t->right,f.second+1});
   
    }
    return;
    
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(A==NULL) {
        vector<vector<int> > ret;
        return ret;
    }
    int maxi=0;
    int mini=0;
    getvals(A,maxi,mini,0);
    vector<vector<int> > diag(maxi-mini+1);
    levelOrder(A,diag,0,mini);
    return diag;
}
