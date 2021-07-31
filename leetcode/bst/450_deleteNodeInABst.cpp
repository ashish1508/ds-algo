
//my approach
// find inorder successor and replace it with the inorder successor  and change left subtree of successor parent to right subtree of successor
class Solution {
public:
    TreeNode* findSuccessor(TreeNode* root){
        TreeNode* parent = NULL;
        
        while(root->left != NULL){
            parent = root;
            root = root->left;
        }
        if(parent)
            parent->left = root->right;
        
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val > key){
            root->left = deleteNode(root->left,key);
            return root;
        }
        if(root->val < key){
            root->right = deleteNode(root->right,key);
            return root;
        }
        if(root->right==NULL) return root->left;
        TreeNode* inSuccessor = findSuccessor(root->right);
        inSuccessor->left = root->left;
        // handle cycle
        if(inSuccessor!=root->right)
            inSuccessor->right = root->right;
        
        return inSuccessor;   
    }
};



// (Easy approach) hp approach
// insert left tree of node in appropriate position in right subtree of node
class Solution {
public:
    TreeNode *findNode(TreeNode *node){
        if(!node->left)return node;
        return findNode(node->left);
    }
    
    TreeNode *call(TreeNode *curr, int key){
        if(!curr)return NULL;
        if(curr->val == key){
            if(curr->right){
                findNode(curr->right)->left = curr->left;
                return curr->right;
            }
            return curr->left;
        }
        if(curr->val > key){
            curr->left = call(curr->left, key);
            return curr;
        }
        curr->right = call(curr->right, key);
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        return call(root, key);
    }
};
