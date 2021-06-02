
class Solution {
public:
    int longestBeautifulSubstring(string word){
        unordered_set<char> us;
        int i=0,j=0,ans=0;
        while(j<word.size()){
            if(j>0 && word[j-1]>word[j]){ 
                i=j;
                us.clear();
            }
            us.insert(word[j]);
            if(us.size()==5)
                ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
