class Solution {
public:
    TreeNode* insertBST(TreeNode* root, int val){
        if(root==NULL) return new TreeNode(val);
        if(root->val > val){
            root->left = insertBST(root->left,val);
            return root;
        }
        root->right = insertBST(root->right,val);
        return root;
        
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertBST(root,val);
    }
};
