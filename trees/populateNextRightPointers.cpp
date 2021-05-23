/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    int cln=1,nln=0;
    queue<TreeNode*> q;
    if(A==NULL) return;
    q.push(A);
    while(!q.empty()){
        TreeNode* f = q.front();
        q.pop();
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
            f->next = NULL;
            cln = nln;
            nln=0;
        }else{
            f->next = q.front();
        }
    }
    
}
