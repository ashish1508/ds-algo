// approach : start a transaction at current or dont - O(n^2)
class Solution {
public:
    vector<vector<int>> cache;
    int go(int s, int transactions_left, vector<int> &prices){
        if(transactions_left==0 || s==prices.size()) return 0;
        if(cache[s][transactions_left]!=-1) return cache[s][transactions_left];
        int ans = go(s+1,transactions_left,prices);
        for(int i=s+1;i<prices.size();i++){
            if(prices[i]>prices[s])
                ans = max(ans,prices[i]-prices[s] + go(i+1,transactions_left-1,prices));
        }
        cache[s][transactions_left] =  ans;
        return cache[s][transactions_left];
    }
    int maxProfit(int k, vector<int>& prices) {
        cache.resize(prices.size(),vector<int>(k+1,-1));
        return go(0,k,prices);
    }
};
