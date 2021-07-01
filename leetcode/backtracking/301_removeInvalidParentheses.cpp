class Solution {
public:
    void removeInvalid(int l,int r,int index,string &path, string &s, int &n, unordered_set<string> &ans){
        
        if(index==s.size() && l==n && r==n){
            ans.insert(path);
            return;
        }
        if(index==s.size()) return;
        
        if(s[index]=='('){
            if(l<n){
                path.push_back('(');
                removeInvalid(l+1,r,index+1,path,s,n,ans);
                path.pop_back(); 
            }
            removeInvalid(l,r,index+1,path,s,n,ans);
        }
        
        if(s[index]==')'){
            if(r<l){
                path.push_back(')');
                removeInvalid(l,r+1,index+1,path,s,n,ans);
                path.pop_back();
            }
            removeInvalid(l,r,index+1,path,s,n,ans);
        }
        
        if(s[index]>='a' && s[index]<='z'){
            path.push_back(s[index]);
            removeInvalid(l,r,index+1,path,s,n,ans);
            path.pop_back();
        }
        
    }
    vector<string> removeInvalidParentheses(string s) {
        int l=0,r=0,n,pairs=0;
        unordered_set<string> ans;
        vector<string> ret;
        string path="";
        
        // Calculate valid pairs
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') l++;
            if(s[i]==')'){
                if(l){
                    pairs++;
                    l--;
                }
            }
        }
        n = pairs;
        
        removeInvalid(0,0,0,path,s,n,ans);
        for(auto i=ans.begin();i!=ans.end();i++)
            ret.push_back(*i);
        
        if(ret.size()==0) ret.push_back("");
        return ret;
    }
};
