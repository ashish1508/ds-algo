/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getAllPaths(TreeNode* root, vector<int> &path, vector<vector<int>> &ans, int targetSum){
        if(root==NULL) return;
        
        path.push_back(root->val);
        targetSum -= root->val;
        if(root->left==NULL && root->right==NULL && targetSum==0){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        if(root->left)
            getAllPaths(root->left, path, ans, targetSum);
        if(root->right)
            getAllPaths(root->right, path, ans, targetSum);
        path.pop_back();
        return;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        getAllPaths(root,path,ans,targetSum);
        return ans;
    }
};
