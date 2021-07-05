// can improve the solution 
// leetcode discuss solutions are great
// top down
class Solution {
public:
    vector<int> cache;
    int getMaxProduct(int n,int l){
        if(n==0 && l==1) return 0;
        if(n==1 || n==0) return 1;
        if(cache[n]!=-1) return cache[n];
        int local_max = INT_MIN,curr_prod;
        for(int i=1;i<=n;i++){
            curr_prod = i * getMaxProduct(n-i,l+1);
            local_max = max(local_max,curr_prod);
        }
        cache[n] = local_max;
        return cache[n];
    }
    int integerBreak(int n) {
        cache.resize(n+1,-1);
        return getMaxProduct(n,0);   
    }
};
