// solution approach and explanation 
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1243038/Detailed-Explanation-with-solution-or-Binary-Search-or-C%2B%2B

class Solution {
public:
    int check(vector<int> &nums, int k, int maxOps){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count += ceil(double(nums[i])/k)-1;
        }
        return count<=maxOps;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
       int lo=1,hi=INT_MAX,mid;
       while(lo<hi){
           mid=lo+(hi-lo)/2;
           if(check(nums,mid,maxOperations)) hi=mid;
           else lo=mid+1;
       } 
       return lo;
    }
};
