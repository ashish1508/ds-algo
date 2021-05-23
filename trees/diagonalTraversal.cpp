/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int getvals(TreeNode* A, int mini){
    if(A==NULL) return 0;
    
    if(A->left){
        int d = getvals(A->left,mini-1);
        return min(d,mini-1);
    }else{
        int d = getvals(A->right,mini+1);
        return min(d,mini+1);
    }
    
} 
void preOrder(TreeNode* A, vector<vector<int> > &diag, int i,int mini){
    if(A==NULL) return;
    diag[i-mini].push_back(A->val);
    preOrder(A->left,diag,i-1,mini);
    preOrder(A->right,diag,i,mini);
    return;
    
}
vector<int> Solution::solve(TreeNode* A) {
    if(A==NULL) {
        vector<int> ret;
        return ret;
    }
    int maxi=0;
    int mini=0;
    mini = getvals(A,mini);
    vector<vector<int> > diag(maxi-mini+1);
    preOrder(A,diag,0,mini);
    vector<int> ret;
    for(int i=diag.size()-1;i>=0;i--){
        int j = 0;
        while(j<diag[i].size()){
            ret.push_back(diag[i][j]);
            j++;
        }
    }
    return ret;
}
