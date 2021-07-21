
// understand problem first

class Solution {
public:
    // void printRight(Node* root, int level, int &max_level, vector<int> &ans){
    //     // if(root==NULL) return;
    //     // if(level>max_level && (root->left || root->right) && level>0){
    //     //     ans.push_back(root->data);
    //     //     max_level = level;
    //     // }
    //     // printRight(root->right,level+1,max_level,ans);
    //     // printRight(root->left,level+1,max_level,ans);
    //     queue<Node* > q;
    //     q.push(root);
    //     int cln=1,nln=0,temp=1;
    //     while(!q.empty()){
    //         Node* f = q.front();
    //         q.pop();
    //         cln--;
    //         if(f->left){
    //             q.push(f->left);
    //             nln++;
    //         }
    //         if(f->right){
    //             q.push(f->right);
    //             nln++;
    //         }
    //         if(cln==0){
    //             if(temp>1 && (f->left || f->right)) ans.push_back(f->data);
    //             cln = nln;
    //             temp = nln;
    //             nln = 0;
    //         }
    //     }
    // }
    // void printLeft(Node* root, int level, int &max_level, vector<int> &ans){
    //     // if(root==NULL) return;
    //     // if(level>max_level && (root->left || root->right) && level>0){
    //     //     ans.push_back(root->data);
    //     //     max_level = level;
    //     // }
    //     // printLeft(root->left,level+1,max_level,ans);
    //     // printLeft(root->right,level+1,max_level,ans);
    //     queue<Node* > q;
    //     q.push(root);
    //     int cln=1,nln=0;
    //     while(!q.empty()){
    //         Node* f = q.front();
    //         q.pop();
    //         cln--;
    //         if(f->left){
    //             q.push(f->left);
    //             nln++;
    //         }
    //         if(f->right){
    //             q.push(f->right);
    //             nln++;
    //         }
    //         if(cln==0){
    //             if(!q.empty() && (q.front()->left || q.front()->right)) ans.push_back(q.front()->data);
    //             cln = nln;
    //             nln = 0;
    //         }
    //     }
    // }
    void printLeft(Node* root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left || root->right)
            ans.push_back(root->data);
        if(root->left) printLeft(root->left,ans);
        else if(root->right) printLeft(root->right,ans);
    }
    void printRight(Node* root, vector<int> &ans){
        if(root==NULL) return;
        if(root->right) printRight(root->right,ans);
        else if(root->left) printRight(root->left,ans);
        if(root->left || root->right)
            ans.push_back(root->data);
    }
    void printLeaves(Node* root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        printLeaves(root->left,ans);
        printLeaves(root->right,ans);
    }
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL) return ans;
        ans.push_back(root->data);
        printLeft(root->left,ans);
        printLeaves(root,ans);
        printRight(root->right,ans);
        return ans;
    }
};
