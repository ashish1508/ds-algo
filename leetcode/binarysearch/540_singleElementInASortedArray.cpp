class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            
            if(mid>0 && nums[mid-1]==nums[mid]){
                if(mid%2) lo=mid+1;
                else hi=mid-2;
            }
            else if(mid<n-1 && nums[mid]==nums[mid+1]){
                if(mid%2) hi=mid-1;
                else lo=mid+2;
            }
            else{
                return nums[mid];
            }
        }
        return nums[lo];
    }
};
