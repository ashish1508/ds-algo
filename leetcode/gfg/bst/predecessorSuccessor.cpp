void findSuc(Node* root, int key, Node*& suc){
    if(root==NULL) return;
    if(root->key > key){
        (suc) = root;
        findSuc(root->left,key,suc);
    }else{
        findSuc(root->right,key,suc);
    }
}
void findPre(Node* root, int key, Node*& pre){
    if(root==NULL) return;
    if(root->key < key){
        (pre) = root;
        findPre(root->right,key,pre);
    }else{
        findPre(root->left,key,pre);
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    findSuc(root,key,suc);
    findPre(root,key,pre);
}
