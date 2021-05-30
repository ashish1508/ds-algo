// lower envelope method
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int> > dq;
        vector<int> v;
        for(int i=0;i<k;i++){
            while(!dq.empty() && dq.back().second<nums[i])
                dq.pop_back();
            dq.push_back({i,nums[i]});
        }
        v.push_back(dq.front().second);
        for(int i=k;i<nums.size();i++){
            if(dq.front().first<i-k+1) dq.pop_front();
            while(!dq.empty() && dq.back().second<nums[i])
                dq.pop_back();
            dq.push_back({i,nums[i]});
            v.push_back(dq.front().second);
        }
        return v;
    }
};
