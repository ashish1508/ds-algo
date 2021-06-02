class Solution {
public:
    bool present(string s, string t){
        
        int j=0;
        for(int i=0;i<s.size();i++){
            if(j<t.size() && s[i]==t[j]) j++;
        }
        if(j==t.size()) return true;
        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";
        sort(dictionary.begin(),dictionary.end());
        for(int i=0;i<dictionary.size();i++){
            if(dictionary[i].size()>ans.size() && present(s,dictionary[i])){
                ans = dictionary[i];
            }
        }
        return ans;
    }
};
