
// bfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        vector<int> level;
        int cln=1,nln=0;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            level.push_back(front->val);
            cln--;
            if(front->left){
                q.push(front->left);
                nln++;
            }
            if(front->right){
                q.push(front->right);
                nln++;
            }
            if(cln==0){
                ans.push_back(level);
                level.clear();
                cln=nln;
                nln=0;
            }
        }
        return ans;
    }
};

// dfs
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<vector<int>> &ans){
        if(root==NULL) return;
        if(level==ans.size()){
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        dfs(root->left,level+1,ans);
        dfs(root->right,level+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,ans);
        return ans;
    }
};
