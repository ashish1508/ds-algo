// idea url : https://massivealgorithms.blogspot.com/2016/10/leetcode-424-longest-repeating.html
// VVVV IMP
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26,0);
        int i=0,j=0,max_count=0,ans=0;
        while(j<s.size()){
            max_count = max(max_count,++v[s[j]-65]);
            if(j-i+1-max_count>k){
                v[s[i]-65]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
