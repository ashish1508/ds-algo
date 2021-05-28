class Solution {
public:
    int isVowel(char s){
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u') return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int i=0,j=0,count=0,ans=0;
        while(j<k){
            if(isVowel(s[j])) count++;
            j++;
        }
        ans=max(ans,count);
        while(j<s.size()){
            if(isVowel(s[j])) count++;
            if(isVowel(s[i])) count--;
            j++;
            i++;
            ans = max(ans,count);
        }
        return ans;
    }
};
