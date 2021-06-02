// implementation can be improved by using while instead of for
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int> > s;
        sort(nums.begin(),nums.end());
        int ans=0,i,j;
        for(i=0,j=1;j<nums.size();i++){
            // if condition for k==0
            if(i==j) j++;
            
            while(j<nums.size() && abs(nums[i]-nums[j])<k) j++;
            if(j<nums.size() && abs(nums[i]-nums[j]) == k) s.insert({nums[i],nums[j]});
        }
        return s.size();
    }
};
