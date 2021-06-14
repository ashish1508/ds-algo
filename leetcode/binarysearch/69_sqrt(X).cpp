// similar to perfect square 367 leetcode problem
class Solution {
public:
    int mySqrt(int x) {
        int lo=1,hi=x,mid;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            long long mnum = 1LL*mid*mid;
            if(mnum< x) lo=mid+1;
            else if(mnum>x) hi=mid-1;
            else return mid;
        }
        return lo-1;
    }
};

