class Solution {
public:
    void getCombinations(int s, int n, int k, vector<int> &path, vector<vector<int>> &ans){
       if(path.size()==k){
           ans.push_back(path);
           return;
       } 
        for(int i=s;i<=n;i++){
            path.push_back(i);
            getCombinations(i+1,n,k,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        getCombinations(1,n,k,path,ans);
        return ans;
    }
};
