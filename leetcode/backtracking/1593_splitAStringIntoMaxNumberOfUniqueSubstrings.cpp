// Approach like palindrome partitioning
class Solution {
public:
    void getPartitions(int s, unordered_set<string> &ss, string &st, int &ans){  
        
        if(s==st.size()){
            if(ss.size()>ans) ans = ss.size();
            return;
        }
        for(int i=s;i<st.size();i++){
            if(ss.find(st.substr(s,i-s+1)) == ss.end()){
                ss.insert(st.substr(s,i-s+1));
                getPartitions(i+1,ss,st,ans);
                ss.erase(st.substr(s,i-s+1));
            }
        }
    }
    int maxUniqueSplit(string s) {
        int ans=0;
        vector<string> path;
        unordered_set<string> ss;
        getPartitions(0,ss,s,ans);
        return ans;
    }
};
