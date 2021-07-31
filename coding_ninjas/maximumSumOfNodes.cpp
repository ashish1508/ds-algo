
// final 450 - 
pair<int,int> maxSum(TreeNode<int> *root){
    if(root==NULL) return {0,0};
    pair<int,int> left = maxSum(root->left);
    pair<int,int> right = maxSum(root->right);
    pair<int,int> curr;
    curr.first = root->data + left.second + right.second;
    curr.second = max(left.first,left.second) + max(right.first,right.second);
    //cout<<root->data<<" : "<<curr.first<<" -- "<<curr.second<<endl;
    return curr;
}
int maximumSumOfNodes(TreeNode<int> *root)
{
	pair<int,int> p  = maxSum(root);
    return max(p.first,p.second);
}
