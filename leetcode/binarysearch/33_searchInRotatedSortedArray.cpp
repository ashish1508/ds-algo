
// my first implementation 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<=hi){
            cout<<lo<<" "<<hi<<endl;
            mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            if((nums[mid]>nums[hi] && target<=nums[hi])  || (nums[mid]>nums[hi] && target>nums[mid]) || (nums[mid]<nums[hi] && target>nums[mid] && target<=nums[hi] )) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};


// below solutions use the fact that one part after or before the middle is sorted
// Comparing with high
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<hi){ 
            mid=lo+(hi-lo)/2;
            cout<<lo<<" "<<mid<<" "<<hi<<endl;
            if(nums[mid]==target) return mid;
            if(nums[mid]>nums[hi]){
                if(target<nums[mid] && target>=nums[lo]) hi=mid-1;
                else lo=mid+1;
            }
            else if(nums[mid]<nums[hi]){
                if(target>nums[mid] && target<=nums[hi]) lo=mid+1;
                else hi=mid-1;
            }
        }
      //Use only low, high can go out of bounds here
        if(nums[lo]==target) return lo;
        return -1;
    }
};

// Comparing with low
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,n=nums.size(),hi=n-1,mid;
        while(lo<hi){ 
            mid=lo+(hi-lo)/2;
            cout<<lo<<" "<<mid<<" "<<hi<<endl;
            if(nums[mid]==target) return mid;
            if(nums[mid]>nums[lo]){
                if(target<nums[mid] && target>=nums[lo]) hi=mid-1;
                else lo=mid+1;
            }
            else if(nums[mid]<nums[lo]){
                if(target>nums[mid] && target<=nums[hi]) lo=mid+1;
                else hi=mid-1;
            }else{
                lo++;
            }
        }
      // use only low here, high can go out of bounds
        if(nums[lo]==target) return lo;
        return -1;
    }
};
