
// tried hard but could not slove on own 
// discuss inspired solution : https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/1224626/C%2B%2B-Solution-with-comments
// have to check time complexity
class Solution {
public:

    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> us;
        vector<int> windex;
        vector<int> ans;
        int sl=s.size(),wl=words[0].size(),ws=words.size(),unique=0;
        for(int i=0;i<words.size();i++){
            us[words[i]]++;
        }
        for(int i=0;i+(ws*wl)<=sl;i++){
            unordered_map<string,int> um;
            for(int j=i;j<i+ws*wl;j+=wl){
                if(us.find(s.substr(j,wl))==us.end()) break;
                um[s.substr(j,wl)]++;
            }
            if(um==us) ans.push_back(i);
        }
        return ans;
    }
};
