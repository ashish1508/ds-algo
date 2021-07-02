
// top down with memoization
class Solution {
public:
    int cache[46];
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        if(cache[n]) return cache[n];
        cache[n] = climbStairs(n-1)+climbStairs(n-2);
        return cache[n];
    }
};

//bottom up
class Solution {
public:
    
    int climbStairs(int n) {
       int cache[n+1];
       cache[0]=1;
       cache[1]=1;
       for(int i=2;i<=n;i++)
           cache[i] = cache[i-1]+cache[i-2];
        return cache[n];
    }
};
