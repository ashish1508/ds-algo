// Sliding window approach
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0,sum=0,ans=0;
        unordered_map<int,int> us;
        while(j<nums.size()){
            
            if(us.find(nums[i])==us.end())
                us[nums[j]]=1;
            else{
                us[nums[j]]++;
            } 
            
            sum += nums[j];
        
            while(i<j && us.size()!=j-i+1){
                us[nums[i]]--;
                if(us[nums[i]]==0)
                    us.erase(nums[i]);
                sum -= nums[i];
                i++;
            }

            ans = max(ans,sum);
            j++;
        }
        return ans;
    }
};
