// top down
class Solution {
public:
    vector<int> cache;
    int LIS(int n, vector<int> &nums){
        if(n==0) return 1;
        int local_max = 1;
        if(cache[n]!=-1) return cache[n];
        for(int i=n-1;i>=0;i--){
            if(nums[n]>nums[i])
              local_max=max(local_max,1+LIS(i,nums));
        }
        cache[n] = local_max;
        return cache[n];
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans=0;
        cache.resize(nums.size(),-1);
        for(int i=nums.size()-1;i>=0;i--){
            ans = max(ans,LIS(i,nums));
        }
        return ans;
    }
};
