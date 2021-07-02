// Had trouble getting base cases right..initially thought for n==0 and n==1 return cost[n] but had to think for a while to get it right 

// top down with memoization
class Solution {
public:
    vector<int> cache;
    int getMinStairs(int n, vector<int> &cost){
        if(n==0 || n==1) return 0;
        if(cache[n]) return cache[n];
        cache[n] = min(getMinStairs(n-1,cost)+cost[n-1],getMinStairs(n-2,cost)+cost[n-2]);
        return cache[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cache.resize(cost.size()+1);
        return getMinStairs(cost.size(),cost);
    }
};

// bottom up
class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()<2) return 0;
        vector<int> cache(cost.size()+1);
        cache[0]=cache[1]=0;
        for(int i=2;i<=cost.size();i++)
            cache[i] = min(cache[i-1]+cost[i-1],cache[i-2]+cost[i-2]);
        return cache[cost.size()];
        
    }
};
