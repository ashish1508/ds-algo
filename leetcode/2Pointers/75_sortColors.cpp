class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=-1,j=nums.size();
        for(int k=0;k<j;k++){
            if(nums[k]==2){
                j--;
                swap(nums[k],nums[j]);
                k--;
            }else if(nums[k]==0){
                i++;
                swap(nums[k],nums[i]);
            } 
        }
    }
};
