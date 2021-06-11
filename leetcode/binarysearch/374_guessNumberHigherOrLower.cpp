//  vvimp read leetcode solution tab regarding ternary search
class Solution {
public:
    int guessNumber(int n) {
        int lo=1,hi=n,mid,ans;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(guess(mid)==0){
                ans=mid;
                break;
            }
            if(guess(mid)==-1) hi=mid-1;
            lo=mid+1;
        }
        return ans;
    }
};
