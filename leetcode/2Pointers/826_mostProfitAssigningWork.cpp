// implementation from leetcode solution tab

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int> >v;
        for(int i=0;i<profit.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        int i=0,j=0,max_profit=0,ans=0;
        for(i=0;i<worker.size();i++){
           while(j<v.size() && v[j].first<=worker[i])
               max_profit = max(max_profit,v[j++].second);
            ans += max_profit;
        }
       
        return ans;
        
    }
};
