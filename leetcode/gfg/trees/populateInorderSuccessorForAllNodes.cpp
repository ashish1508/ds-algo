
// my solution (easy)

class Solution
{
public:
    void reverseInorder(Node* root, Node* &temp){
        if(root==NULL) return;
        reverseInorder(root->right,temp);
        root->next = temp;
        temp = root;
        reverseInorder(root->left,temp);
    }
    void populateNext(Node *root)
    {
        //code here
        Node* temp = NULL;
        reverseInorder(root,temp);
    }
};

// hp solution (complicated)
class Solution
{
public:
    Node* inorder(Node *root, Node *parent){
        if(!root)return NULL;
        Node *left = inorder(root->left, root);
        root->next = parent;
        Node *right = inorder(root->right, parent);
        if(right){
            root->next = right;
        };
        if(left)return left;
        return root;
    }
    
    void populateNext(Node *root)
    {
        inorder(root, NULL);
    }
};
