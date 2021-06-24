class Solution {
public:
    void getCombinations(int s, int &target, vector<int> &candidates, vector<int> &path, vector<vector<int>> &ans){
        if(target<0) return;
        if(target==0){
           ans.push_back(path);
           return;
        } 
        for(int i=s;i<candidates.size();i++){
            path.push_back(candidates[i]);
            target -= candidates[i];
            getCombinations(i,target,candidates,path,ans);
            target += candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        getCombinations(0,target,candidates,path,ans);
        return ans;
    }
};

