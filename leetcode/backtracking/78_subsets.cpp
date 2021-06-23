class Solution {
public:
    void getSubsets(vector<vector<int>> &ans, vector<int> &nums, vector<int> &path, int s){
        
        ans.push_back(path);
        // no need of this return statement but if we write runtime is very less
        if(s==nums.size()) return;
        for(int i=s;i<nums.size();i++){
            path.push_back(nums[i]);
            getSubsets(ans,nums,path,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        getSubsets(ans,nums,path,0);
        return ans;
    }
};
