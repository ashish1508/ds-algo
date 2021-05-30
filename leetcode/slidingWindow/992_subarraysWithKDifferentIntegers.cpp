//vvimp 
class Solution {
public:
    int subarrayWithAtmostKDistinct(vector<int>& nums, int k){
        int i=0,j=0,count=0,unique=0;
        vector<int> v(nums.size()+1,0);

        while(j<nums.size()){
            if(v[nums[j]]==0) unique++;
            v[nums[j]]++;
            while(unique>k){
                if(v[nums[i]]==1) unique--;
                v[nums[i]]--;
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithAtmostKDistinct(nums,k)-subarrayWithAtmostKDistinct(nums,k-1);
    }
};
