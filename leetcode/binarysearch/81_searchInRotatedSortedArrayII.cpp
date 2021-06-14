// my implementation
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<=hi){
            cout<<lo<<" "<<hi<<endl;
            mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            if((nums[mid]>nums[hi] && target<=nums[hi])  || (nums[mid]>nums[hi] && target>nums[mid]) || (nums[mid]<nums[hi] && target>nums[mid] && target<=nums[hi] )) lo=mid+1;
            else if(nums[mid]==nums[hi]) hi--;
            else hi=mid-1;
        }
        return -1;
    }
};


// below solutions use the fact that part below or after the mid remains sorted
// comparing with low
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<=hi){ 
            mid=lo+(hi-lo)/2;
            cout<<lo<<" "<<mid<<" "<<hi<<endl;
            if(nums[mid]==target) return true;
            if(nums[mid]>nums[lo]){
                if(target<nums[mid] && target>=nums[lo]) hi=mid-1;
                else lo=mid+1;
            }
            else if(nums[mid]<nums[lo]){
                if(target>nums[mid] && target<=nums[hi]) lo=mid+1;
                else hi=mid-1;
            }else{
              // in this case we cant deecide the search space so remove first element from search space as its equal to mid val which is not equal to target
              // decrease search space : example 1,1,1,3,1 : 1,3,1,1,1
                lo++;
            }
            
        }
        return false;
    }
};

// comparing with high
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<=hi){ 
            mid=lo+(hi-lo)/2;
            cout<<lo<<" "<<mid<<" "<<hi<<endl;
            if(nums[mid]==target) return true;
            if(nums[mid]>nums[hi]){
                if(target<nums[mid] && target>=nums[lo]) hi=mid-1;
                else lo=mid+1;
            }
            else if(nums[mid]<nums[hi]){
                if(target>nums[mid] && target<=nums[hi]) lo=mid+1;
                else hi=mid-1;
            }else{
                hi--;
            }
            
        }
        return false;
    }
};
