class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0,mid,n=nums.size(),hi=n-1;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid]>nums[n-1]) lo=mid+1;
            if(nums[mid]<nums[n-1]) hi=mid;
        }
        return nums[lo];
    }
};
