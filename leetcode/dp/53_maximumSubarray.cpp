
// getMaxSubArray(n) returns maxsubarray sum ending at n
// top down approach
// Actually it is not a dp problem because there are no overlapping subproblems..we can do it without cache
class Solution {
public:

    vector<int> cache;
    int getMaxSubArray(int n, vector<int> &nums){
        if(n==0) return cache[0];
        if(cache[n]!=INT_MIN) return cache[n];
        cache[n] = max(nums[n],nums[n]+getMaxSubArray(n-1,nums));
        return cache[n];
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        cache.resize(n,INT_MIN);
        cache[0]=nums[0];
        getMaxSubArray(n-1,nums);
        int ans = INT_MIN;
        for(int i=0;i<cache.size();i++)
            ans = max(ans,cache[i]);
        return ans;
        
    }
};

// top down without cache
class Solution {
public:
    int ans;
    int getMaxSubArray(int n, vector<int> &nums){
        if(n==0) return nums[0];
        int val = max(nums[n],nums[n]+getMaxSubArray(n-1,nums));
        ans = max(ans,val);
        return val;
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        ans = nums[0];
        getMaxSubArray(n-1,nums);
        return ans;
        
    }
};

// bottom up
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> cache;
        cache.resize(n,INT_MIN);
        cache[0]=nums[0];
        int ans = cache[0];
        for(int i=1;i<n;i++){
            cache[i] = max(nums[i],nums[i]+cache[i-1]);
            ans = max(ans,cache[i]);
        }
        return ans;
    }
};

// bottom up with no cache
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        int ans = nums[0];
        for(int i=1;i<n;i++){
            nums[i] = max(nums[i],nums[i]+nums[i-1]);
            ans = max(ans,nums[i]);
        }
        return ans;
    }
};

