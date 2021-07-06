
// have to do better solutions 
// leetcode solution tab
// top down - O(n^3)
class Solution {
public:
    vector<vector<vector<int>>> cache;
    bool go(int i, int j, int k, string &s1, string &s2, string &s3){
        if(k==s3.size()) return true;
        if(cache[i][j][k]!=-1) return cache[i][j][k];
        int first=false,second=false;
        if(i<s1.size() && s3[k]==s1[i]) first =  go(i+1,j,k+1,s1,s2,s3);
        if(j<s2.size() && s3[k]==s2[j]) second = go(i,j+1,k+1,s1,s2,s3);
        cache[i][j][k] = first || second ;
        return cache[i][j][k];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size()) return false;
        cache.resize(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return go(0,0,0,s1,s2,s3);
    }
};
