// math approaches are also there in discuss
// backtracking approach
class Solution {
public:
    void getVowelStrings(int s, int &n, int &ans){
        if(n==0){
            ans++;
            return;
        }
        for(int i=s;i<5;i++){
            n--;
            getVowelStrings(i,n,ans);
            n++;
        }
        return;
    }
    int countVowelStrings(int n) {
        int ans=0;
        getVowelStrings(0,n,ans);
        return ans;
    }
};
