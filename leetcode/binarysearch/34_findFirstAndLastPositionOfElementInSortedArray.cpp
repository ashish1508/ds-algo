class Solution {
public:
    int start(vector<int> &nums, int target){
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid]<target) lo=mid+1;
            if(nums[mid]>=target) hi=mid-1;
        }
        return hi;
    }
    int end(vector<int> &nums, int target){
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid]<=target) lo=mid+1;
            if(nums[mid]>target) hi=mid;
        }
        return lo;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        //if(nums.size()==0) return {-1,-1};
        //if(target>nums[nums.size()-1] || target<nums[0]) return {-1,-1};
        vector<int> vec;
        int s = start(nums,target);
        int e = end(nums,target);
        // cout<<s<<" "<<e<<endl;
        if(nums.size()>0 && nums[e]==target) e++;
        if(s+1>e-1) return {-1,-1};
        return {s+1,e-1};
    }
};
