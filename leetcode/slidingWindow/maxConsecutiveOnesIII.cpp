class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s=0,e=0,count=0,ans=0;
        
        while(e<nums.size()){
            if(nums[e]==0)
                count++;
            if(count>k){
                while(nums[s]!=0 && s<e) s++;
                s++;
                count--;
            }else{
                ans = max(ans,e-s+1);
            }
            e++;
        }
        return ans;
    }
};
