// top down
class Solution {
public:
    vector<vector<int>> cache;
    int getLCS(int t1, int t2, string &text1, string &text2){
        if(t1==0 || t2==0) return 0;
        if(cache[t1][t2]!=-1) return cache[t1][t2];
        if(text1[t1-1]==text2[t2-1]){
            return 1+getLCS(t1-1,t2-1,text1,text2);
        }
        cache[t1][t2] = max(getLCS(t1-1,t2,text1,text2),getLCS(t1,t2-1,text1,text2));
        return cache[t1][t2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        cache.resize(text1.size()+1,vector<int>(text2.size()+1,-1));
        return getLCS(text1.size(),text2.size(),text1,text2);
    }
};
