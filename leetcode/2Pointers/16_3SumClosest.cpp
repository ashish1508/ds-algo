class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int j,k,dist=INT_MAX,ans,sum;
        for(int i=0;i<nums.size()-1;i++){
            j = i+1;
            k = nums.size()-1;
            while(j<k){
                  sum = nums[i]+nums[j]+nums[k];
                  if(abs(target-sum)<dist){
                      dist = abs(target-sum);
                      ans = sum;
                  }
                if(sum<target) j++;
                else if(sum>target) k--;
                else return sum;   
            }
        }
        return ans;
    }
};
