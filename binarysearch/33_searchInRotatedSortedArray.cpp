class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<=hi){
            //cout<<lo<<" "<<hi<<endl;
            mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            if((nums[mid]>nums[hi] && target<=nums[hi])  || (nums[mid]>nums[hi] && target>nums[mid]) || (nums[mid]<nums[hi] && target>nums[mid] && target<=nums[hi] )) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};
