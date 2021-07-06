
// first thought was like it would be variant of LIS which is true if we see in one perspective i.e sort by start time and think that curr_job is the last job of LIS
// have implemented O(n^2) approach .. can do it iin O(nlogn) using binary search (see in labuladong gitbook)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>> vp;
        for(int i=0;i<startTime.size();i++)
            vp.push_back({{startTime[i],endTime[i]},profit[i]});
        sort(vp.begin(),vp.end());
        vector<int> cache(vp.size());
        int ans=INT_MIN;
        for(int i=0;i<vp.size();i++){
            cache[i] = vp[i].second;
            for(int j=i-1;j>=0;j--){
                if(vp[j].first.second<=vp[i].first.first) cache[i] = max(cache[i],cache[j]+vp[i].second);
            }
            ans = max(ans,cache[i]);
        }
        return ans;
    }
};
// bottom up approach which I thought (but never go bottom up in dp..always think top down) : sort by start time and think the curr_job is the first job of the LIS
// top down approach : current element can be part of lis or not if yes get the index of next element or go to next element
// here cache[i] stores the max LIS using all next elements
// top down approach - https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/733167/Thinking-process-Top-down-DP-Bottom-up-DP
// bottom up
class Solution {
public:
    static bool comp(vector<int> v1, vector<int> v2){
        return v1[0]<v2[0];
    }
    int binarySearch(int lo, int hi, int val, vector<vector<int>> &vp){
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(vp[mid][0]<val) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> vp;
        for(int i=0;i<startTime.size();i++)
            vp.push_back({startTime[i],endTime[i],profit[i]});
        sort(vp.begin(),vp.end(),comp);
        int n = vp.size();
        vector<int> cache(n,0);
        cache[n-1] = vp[n-1][2];
        int final_ans=cache[n-1],curr_ans = cache[n-1];
        for(int i=vp.size()-2;i>=0;i--){
            int ind = binarySearch(i+1,vp.size()-1,vp[i][1],vp);
            cache[i] = vp[i][2];
            if(vp[ind][0]>=vp[i][1])
                cache[i] += cache[ind];
            cache[i] = max(cache[i],cache[i+1]);
        }
        return cache[0];
    }
};
