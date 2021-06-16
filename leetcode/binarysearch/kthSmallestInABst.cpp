// Recursive implementation
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(root==NULL) return 0;
        int ans = kthSmallest(root->left,k);
        k--;
        if(k==0) ans += root->val;
        ans += kthSmallest(root->right,k);
        return ans;
        
    }
};

// iterative implementation will be much faster as we can break after k elements
// other solutions in leetcode solution tab are also ver good..have a look at it
