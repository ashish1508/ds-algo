// not dp
// Two pointers type
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        for(;i<t.size() && j<s.size();i++){
            if(t[i]==s[j]) j++;
        }
        if(j==s.size()) return true;
        return false;
    }
};

// Follow up with binary search great solution
