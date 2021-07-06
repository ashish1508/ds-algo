// Leetcode solution tab - other solutions with O(n^2) time, O(1) space and O(n) time (MANACHER'S ALGORITHM)

// bottom up
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> cache(s.size(),vector<int>(s.size(),false));
        string ans;
        int si=0,l=1;
        ans.append(1,s[0]);
        for(int i=0;i<s.size();i++)
            cache[i][i]=true;
        
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                cache[i][i+1] = true;
                si=i,l=2;
            }
        }
        for(int gap=2;gap<s.size();gap++){
            for(int i=0;i<s.size()-gap;i++){
                int j = i+gap;
                if(s[i]==s[j] && cache[i+1][j-1]){
                    si=i,l=j-i+1;
                    cache[i][j]=true;
                }else{
                    cache[i][j] = false;
                }
            }
        }
        return s.substr(si,l);
    }
};
