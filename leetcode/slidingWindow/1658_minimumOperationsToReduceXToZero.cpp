class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0,j=0,len=0,sum=0,ans=INT_MIN,total=0;
        
        for(int k=0;k<nums.size();k++)
            total += nums[k];
        
        // if x is the sum of all numbers
        if(total=x) return nums.size();
        
        while(j<nums.size()){
            sum += nums[j];
            while(sum>total-x && i<j){
                sum -= nums[i];
                i++;
            }
            if(sum==total-x)
                ans=max(ans,j-i+1);
            j++;
        }
        if(ans==INT_MIN) return -1;
        return nums.size()-ans;
    }
};
