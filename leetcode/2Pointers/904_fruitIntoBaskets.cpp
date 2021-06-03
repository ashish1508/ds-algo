class Solution {
public:

    int totalFruit(vector<int>& tree) {
        int i=0,j=0,ans=0;
        unordered_map<int,int> um;
        while(j<tree.size()){
            if(um.find(tree[j])==um.end()) um[tree[j]]=1;
            else um[tree[j]]++;
            while(i<j && um.size()>2){
                um[tree[i]]--;
                if(um[tree[i]]==0) um.erase(tree[i]);
                i++;
            }
            if(um.size()<=2) ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
