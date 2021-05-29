// easy implementation
class Solution {
public:

    int lengthOfLongestSubstring(string s) {
       vector<int> v(128,0);
        int i=0,j=0, n=s.size(),ans=0;
        while(j<n){
            v[s[j]]++;
            
            while(v[s[j]]>1 && i<j){
                v[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    
};




// first implementation

class Solution {
public:
    int onesAndZeroes(vector<int> &v){
        for(int i=0;i<v.size();i++){
            if(v[i]!=0 && v[i]!=1) return 0;
        }
        return 1;
    }
    int lengthOfLongestSubstring(string s) {
       vector<int> v(128,0);
        int i=0,j=0, n=s.size(),ans=0;
        while(j<n){
            v[s[j]-'\0']++;
            
            while(!onesAndZeroes(v) && i<j){
                v[s[i]-'\0']--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
