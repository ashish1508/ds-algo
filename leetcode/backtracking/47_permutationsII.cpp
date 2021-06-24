
// keep track of all unique numbers at every position
class Solution {
public:
    void getPermutations(vector<int> &nums, vector<int> &path, unordered_map<int,int> &m, vector<vector<int>> &ans){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(auto i=m.begin();i!=m.end();i++){
            int val = i->first;
            int coun = i->second;
            if(coun==0) continue;
            m[val]--;
            path.push_back(val);
            getPermutations(nums,path,m,ans);
            path.pop_back();
            m[val]++;
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_map<int,int> m;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;

        getPermutations(nums,path,m,ans);
        return ans;
    }
};










