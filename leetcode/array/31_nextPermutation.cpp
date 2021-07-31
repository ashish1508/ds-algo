class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i,swap_index;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) {
                break;
            }
        }
        if(i>=0){
            swap_index=i+1;
            for(int j=i+2;j<n;j++){
                if(nums[j]>nums[i] && nums[j]<nums[swap_index])
                    swap_index = j;
            }
            swap(nums[i],nums[swap_index]);
            
        }
        sort(nums.begin()+i+1,nums.end());
    }
};
