class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void getInorder(Node* root,vector<int> &vec){
        if(root==NULL) return;
        getInorder(root->left,vec);
        vec.push_back(root->data);
        getInorder(root->right,vec);
    }
    void putInorder(Node* root, int &index, vector<int> &vec){
        if(root==NULL) return;
        putInorder(root->left,index,vec);
        root->data = vec[index];
        index++;
        putInorder(root->right,index,vec);
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> vec;
        getInorder(root,vec);
        sort(vec.begin(),vec.end());
        int index=0;
        putInorder(root,index,vec);
        return root;
    }
};
