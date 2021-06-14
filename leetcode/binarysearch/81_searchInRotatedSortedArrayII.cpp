// comapring with low
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
