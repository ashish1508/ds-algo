// can visit leetcode solution tab for solution complexity and other solutions
class Solution {
public:
    void getParenthesis(vector<string> &ans, string &s, int n, int l, int r){
        
        if(l==n && r==n){
            ans.push_back(s);
            return;
        }
        if(l<n){
            s.append(1,'(');
            getParenthesis(ans,s,n,l+1,r);
            s.pop_back();  
        }
        if(r<l){
            s.append(1,')');
            getParenthesis(ans,s,n,l,r+1);
            s.pop_back(); 
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        getParenthesis(ans,s,n,0,0);
        return ans;
    }
};
