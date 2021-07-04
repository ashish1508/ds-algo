
// top down
class Solution {
public:
    vector<int> cache;
    int minCoins(int amount, vector<int> &coins){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(cache[amount]!=-1) return cache[amount];
        int local_min = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int temp = minCoins(amount-coins[i],coins);
            if(temp!=INT_MAX)
                local_min = min(local_min,1+temp);
        }
        cache[amount] = local_min;
        return cache[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        cache.resize(amount+1,-1);
        int ans = minCoins(amount,coins);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

// bottom up
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache;
        cache.resize(amount+1,0);
        cache[0] = 0;
        for(int curr_amount=1;curr_amount<=amount;curr_amount++){
            int local_min = INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(curr_amount-coins[j] < 0) continue;
                int temp = cache[curr_amount-coins[j]];
                if(temp!=INT_MAX)
                    local_min = min(local_min,1+temp);
            }
            cache[curr_amount] = local_min;
        }
        if(cache[amount]==INT_MAX) return -1;
        return cache[amount];
    }
    
};
