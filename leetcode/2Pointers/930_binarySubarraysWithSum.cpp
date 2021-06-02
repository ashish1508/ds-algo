// same as 1248 leetcode problem
class Solution {
public:
    int subarrayWithAtmostSum(vector<int>& nums, int goal){
        int i=0,j=0,sum=0,ans=0;
        while(j<nums.size()){
            sum += nums[j];
            while(i<=j && sum>goal){
                sum -= nums[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarrayWithAtmostSum(nums, goal)-subarrayWithAtmostSum(nums,goal-1);
    }
};
