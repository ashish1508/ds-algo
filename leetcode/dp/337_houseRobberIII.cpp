// approach : rob current house or not
// top down
class Solution {
public:
    unordered_map<TreeNode*,int> um;
    int go(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        if(um.find(root)!=um.end()) return um[root];
        int without = go(root->left) + go(root->right);
        int with = root->val;
        if(root->left){
            with += go(root->left->left) + go(root->left->right);
        }
        if(root->right)
            with += go(root->right->left) + go(root->right->right);
        um[root] = max(with,without);
        return um[root];
    }
    int rob(TreeNode* root) {
        return go(root);
    }
};
