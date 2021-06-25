
// Iterative approach from leetcode discuss tab https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8090/Iterative-c%2B%2B-solution-in-0ms
// Bactracking approach
class Solution {
public:
    void getCombinations(int s, string &path, vector<string> &vs, string &digits, vector<string> &dialpad){
        if(path.size()==digits.size()){
            vs.push_back(path);
            return;
        }
        for(int i=0;i<dialpad[digits[s]-'2'].size();i++){
            path.append(1,dialpad[digits[s]-'2'][i]);
            getCombinations(s+1,path,vs,digits,dialpad);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> dialpad = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> vs;
        string s="";
        getCombinations(0,s,vs,digits,dialpad);
        return vs;
    }
};
