class Solution {
public:
    void printMap(map<int,int> &m){
        for(auto im=m.begin();im!=m.end();im++)
            cout<<im->first<<" "<<im->second<<endl;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> m;
        int i=0,j=0,n=nums.size(),ans=0;
        while(j<n){
            
            if(m.find(nums[j])==m.end()) m.insert({nums[j],1});
            else{
                auto k = m.find(nums[j]);
                (k->second)++;
                
            }
            while(i<j && abs(m.begin()->first - m.rbegin()->first) > limit){
                auto t = m.find(nums[i]);
                if(t->second==1) m.erase(nums[i]);
                else (t->second)--;
                i++;
            }
           
            ans = max(ans,j-i+1);
            j++;
            
        }
        return ans;
    }
};
