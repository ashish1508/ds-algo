
// top down
class Solution {
public:
    vector<vector<int>> cache;
    int LPS(int s, int e, string &st){
        if(s>e) return 0;
        if(s==e) return 1;
        if(cache[s][e]!=-1) return cache[s][e];
        int with=0,without=0;
        if(st[s]==st[e]) with = 2+LPS(s+1,e-1,st);
        without = max(LPS(s+1,e,st),LPS(s,e-1,st));
        cache[s][e] = max(with,without);
        return cache[s][e];
    }
    int longestPalindromeSubseq(string s) {
        cache.resize(s.size(),vector<int>(s.size(),-1));
        return LPS(0,s.size()-1,s);
    }
};

// bottom up
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> cache;
        cache.resize(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++)
            cache[i][i]=1;
        for(int gap=1;gap<s.size();gap++){
            for(int i=0;i<s.size()-gap;i++){
                int j=i+gap;
                int with=0,without=0;
                if(s[i]==s[j])
                    with = 2+cache[i+1][j-1];
                without = max(cache[i+1][j],cache[i][j-1]);
                cache[i][j] = max(with,without);
            }
        }
        return cache[0][s.size()-1];
    }
};
