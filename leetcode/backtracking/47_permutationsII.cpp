

// like normal permutations with unordered_set to maintain unique numbers
class Solution {
public:
    void getPermutations(vector<int> &nums, vector<int> &path, int s, vector<vector<int>> &ans){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        unordered_set<int> us;
        for(int i=s;i<nums.size();i++){
            if(us.find(nums[i])!=us.end()) continue;
            us.insert(nums[i]);
            swap(nums[i],nums[s]);
            path.push_back(nums[s]);
            getPermutations(nums,path,s+1,ans);
            path.pop_back();
            swap(nums[i],nums[s]);
            
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        getPermutations(nums,path,0,ans);
        return ans;
    }
};


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










