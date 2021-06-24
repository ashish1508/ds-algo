class Solution {
public:
    void getCombinations(int s, int &target, vector<int> &candidates, vector<int> &path, vector<vector<int>> &ans){
        if(target<0) return;
        if(target==0){
           ans.push_back(path);
           return;
        } 
        for(int i=s;i<candidates.size();i++){
            if(i!=s &&  candidates[i]==candidates[i-1]) continue;
            path.push_back(candidates[i]);
            target -= candidates[i];
            getCombinations(i+1,target,candidates,path,ans);
            target += candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        getCombinations(0,target,candidates,path,ans);
        return ans;
    }
};
