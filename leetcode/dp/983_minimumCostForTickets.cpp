
// can use binary search instead of linear search
// top down
class Solution {
public:
    vector<int> cache;
    int getMinCosts(int s,vector<int>& days, vector<int>& costs){
        if(s==days.size()) return 0;
        if(cache[s]!=INT_MAX) return cache[s];
        int c1 = costs[0]+getMinCosts(s+1,days,costs);
        int i;
        for(i=0;i<days.size();i++)
            if(days[i]>days[s]+6) break;
        int c2 = costs[1]+getMinCosts(i,days,costs);
        for(;i<days.size();i++)
            if(days[i]>days[s]+29) break;
        int c3 = costs[2]+getMinCosts(i,days,costs);
        cache[s] = min({c1,c2,c3});
        return cache[s];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        cache.resize(days.size()+1,INT_MAX);
        return getMinCosts(0,days,costs);
    }
};

// bottom up
class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> cache;
        cache.resize(days.size()+1,0);
        for(int i=days.size()-1;i>=0;i--){
            int c1 = costs[0]+cache[i+1];
            int j;
            for(j=0;j<days.size();j++)
                if(days[j]>days[i]+6) break;
            int c2 = costs[1]+cache[j];
            for(;j<days.size();j++)
                if(days[j]>days[i]+29) break;
            int c3 = costs[2]+cache[j];
            cache[i] = min({c1,c2,c3});
        }
        return cache[0];
    }
};

