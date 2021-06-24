class Solution {
public:
        void getCombinations(int s, vector<int> &path, int &n, int k, vector<vector<int>> &ans){
        if(n<0 || path.size()>k) return;
        if(n==0 && path.size()==k){
           ans.push_back(path);
           return;
        } 
        for(int i=s;i<=9;i++){
            path.push_back(i);
            n -= i;
            getCombinations(i+1,path,n,k,ans);
            n += i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        getCombinations(1,path,n,k,ans);
        return ans;
    }
};

