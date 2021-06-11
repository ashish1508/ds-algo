class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) lo = mid+1;
            if(nums[mid]>target)hi=mid;
        }
        if(nums[lo]<target) return n;
        return lo;
    }
};
