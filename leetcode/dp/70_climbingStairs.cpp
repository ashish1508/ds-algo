class Solution {
public:
    int cache[46];
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        if(cache[n]) return cache[n];
        cache[n] = climbStairs(n-1)+climbStairs(n-2);
        return cache[n];
    }
};
