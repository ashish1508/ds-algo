
// VVIMP
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_set<char> us;
        for(int i=0;i<s.size();i++)
            us.insert(s[i]);
        int tu = us.size(), n=s.size(), ans=0;
        for(int cu=1; cu<=tu ; cu++){
            int u=0, ck=0, i=0, j=0;
            vector<int> vec(26,0);
            while(j<n){
              if(u<=cu){
                  vec[s[j]-'a']++;
                  if(vec[s[j]-'a']==1)
                      u++;
                  if(vec[s[j]-'a']==k)
                      ck++;
                  j++;
                  
              }else{
                  
                  vec[s[i]-'a']--;
                  if(vec[s[i]-'a']==0)
                      u--;
                  if(vec[s[i]-'a']==k-1)
                      ck--;
                  i++;
              } 
              if(u==cu && ck==cu)
                  ans = max(ans,j-i);
            }
        }
        return ans;
    }
};
