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
