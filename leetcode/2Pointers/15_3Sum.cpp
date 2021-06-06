class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> temp;
        int n = nums.size(),sum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            while(i>0 && i<n && nums[i]==nums[i-1]) i++;
            if(i==n) break;
            int j=i+1;
            int k=n-1;
            while(j<k){
                sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    temp.clear();
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    v.push_back(temp);
                    while(j<k && nums[j]==nums[j+1])
                        j++;
                    j++;
                }else if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }
            }
            
        }
        
        return v;
    }
};
