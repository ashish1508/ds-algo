// approach : consider nums[i] iis trhe last burst balloon in [s...i...e] subarray
// leetcode discuss :  https://leetcode.com/problems/burst-balloons/discuss/194608/DP-solution-with-detailed-text-and-video-explanation. 
// This is also great : https://leetcode.com/problems/burst-balloons/discuss/76228/Share-some-analysis-and-explanations
// top down
class Solution {
public:
    vector<vector<int>> cache;
    int getMaxCoins(int s, int e, vector<int> &nums){
        if(s>e) return 0;
        if(cache[s][e]!=0) return cache[s][e];
        int local_max=INT_MIN,pi,ni,prev,next;
        for(int i=s;i<=e;i++){
            prev=next=1;
            if(s-1>=0) prev = nums[s-1];
            if(e+1<nums.size()) next=nums[e+1];
            local_max = max(local_max, prev*nums[i]*next + getMaxCoins(s,i-1,nums) + getMaxCoins(i+1,e,nums));
        }
        cache[s][e]=local_max;
        return cache[s][e];
    }
    int maxCoins(vector<int>& nums) {
        cache.resize(nums.size(),vector<int>(nums.size(),0));
        return getMaxCoins(0,nums.size()-1,nums);
    }
};

// bottom up
class Solution {
public:
    

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> cache;
        cache.resize(nums.size(),vector<int>(nums.size(),0));
        int prev,next,local_max;

        for(int gap=0;gap<n;gap++){
            for(int i=0;i<n-gap;i++){
                int j = i+gap;
                local_max = INT_MIN;
                for(int k=i;k<=j;k++){
                    prev=next=1;
                    if(i-1>=0) prev = nums[i-1];
                    if(j+1<nums.size()) next=nums[j+1];
                    int left = (k-1 < 0) ? 0 : cache[i][k-1];
                    int right = (k+1 > n-1) ? 0 : cache[k+1][j];
                    local_max = max(local_max, prev*nums[k]*next + left + right );
                }
                cache[i][j]=local_max;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //         cout<<cache[i][j]<<" ";
        //     cout<<endl;
        // }
        return cache[0][nums.size()-1];
    }
};
