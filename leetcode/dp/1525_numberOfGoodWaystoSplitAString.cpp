class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> um;
        for(int i=0;i<s.size();i++)
            um[s[i]]++;
        int ans=0;
        unordered_map<char,int> uc;
        for(int i=0;i<s.size();i++){
            if(um[s[i]]==1) 
                um.erase(s[i]);
            else um[s[i]]--;
            uc[s[i]]++;
            if(uc.size() == um.size())
                ans++;
        }
        return ans;    
    }
};
