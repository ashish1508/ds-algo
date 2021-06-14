
class Solution {
public:
    bool isPerfectSquare(int num) {
      // we can also initialize hi=num so that we can also cover n==1 case and rum time will increase
      // but as we know that square root exists less than or equal to half of num we used hi=num/2 to reduce run time
        int lo=1,hi=num/2,mid;
        if(num==1) return true;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
          // use long long to prevent overflow
            long long mnum = 1LL*mid*mid;
            if(mnum< num) lo=mid+1;
            else if(mnum>num) hi=mid-1;
            else return true;
        }
        return false;
    }
};
