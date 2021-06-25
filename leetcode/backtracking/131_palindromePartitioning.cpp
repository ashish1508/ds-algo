class Solution {
public:
    bool isPalindrome(int s,int e,string &st){
        while(s<=e){
            if(st[s]!=st[e]) return false;
            s++;e--;
        }
        return true;
    }
    void getPartitions(int s, vector<string> &path, string &st, vector<vector<string>> &ans){  
        
        if(s==st.size()){
            ans.push_back(path);
            return;
        }
        for(int i=s;i<st.size();i++){
            if(isPalindrome(s,i,st)){
                path.push_back(st.substr(s,i-s+1));
                getPartitions(i+1,path,st,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        getPartitions(0,path,s,ans);
        return ans;
    }
};
