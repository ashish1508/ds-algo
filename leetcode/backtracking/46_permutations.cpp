class Solution {
public:
    void getPermutations(vector<int> &nums, vector<int> &path, int s, vector<vector<int>> &ans){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=s;i<nums.size();i++){
            swap(nums[i],nums[s]);
            path.push_back(nums[s]);
            getPermutations(nums,path,s+1,ans);
            path.pop_back();
            swap(nums[i],nums[s]);
            
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        getPermutations(nums,path,0,ans);
        return ans;
    }
};
