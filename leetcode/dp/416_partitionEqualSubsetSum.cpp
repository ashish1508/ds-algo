
// top down
class Solution {
public:
    vector<vector<int>> cache;
    // gets if we can get amount with elements starting from ith index 
    int getPartitions(int i,int amount,vector<int> &nums){
        if(amount==0) return 1;
        if(i==nums.size()) return 0;
        bool used = 0, no_used = 0;
        if(cache[i][amount] != -1) return cache[i][amount];
        if(amount>=nums[i])
            used = getPartitions(i+1,amount-nums[i],nums);
        no_used = getPartitions(i+1,amount,nums);
        cache[i][amount] = max(used,no_used);
        return cache[i][amount];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num : nums)
            sum += num;
        if(sum%2) return false;
        cache.resize(nums.size(),vector<int>(sum/2+1,-1));
        return getPartitions(0,sum/2,nums);
    }
};

// bottom up
class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num : nums)
            sum += num;
        if(sum%2) return false;
        vector<vector<int>> cache;
        cache.resize(nums.size()+1,vector<int>(sum/2+1,0));
        for(int j=0;j<sum/2+1;j++)
            cache[nums.size()][j]=0;
        for(int i=0;i<=nums.size();i++)
            cache[i][0]=1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=1;j<sum/2+1;j++){
                int used = 0, no_used = 0;
                if(j>=nums[i])
                    used = cache[i+1][j-nums[i]];
                no_used = cache[i+1][j];
                cache[i][j] = max(used,no_used);
            }
        }
        return cache[0][sum/2];
    }
    
};
