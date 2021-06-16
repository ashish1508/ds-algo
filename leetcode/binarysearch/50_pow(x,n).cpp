// should not be in binary search ...it is divide and conquer
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            // multiplication with -1LL to handle INT_MIN case
            return 1/pow(x,-1LL*n);
        }
        if(n==double(1)) return x;
        if(n==0) return double(1);
        if(n%2) return myPow(x,n/2)*myPow(x,n/2+1);
        double d = myPow(x,n/2);
        return d*d;
            
    }
};
