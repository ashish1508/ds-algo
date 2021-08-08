class Solution {
public:
    TreeNode* arrToBst(int s, int e, vector<int> &arr){
        if(s>e) return NULL;
        if(s==e) return new TreeNode(arr[s]);
        int mid = s+(e-s)/2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = arrToBst(s,mid-1,arr);
        node->right = arrToBst(mid+1,e,arr);
        return node;
    }
    void inorder(TreeNode* root, vector<int> &arr){
        if(root==NULL) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return arrToBst(0,arr.size()-1,arr);
    }
};
