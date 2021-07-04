// best approach : go throught all the adjacent repeating alphabets ..add total cost - max cost of adjacent repeating alphabets to the answer
// worst approach : vive versa of best approach
// my first implementation : worst approach using multiset
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        if(s.size()==1) return 0;
        int ans=0;
        multiset<int> ms;
        ms.insert(cost[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                ms.insert(cost[i]);
            }else{
                while(ms.size()>1){
                    ans += *(ms.begin());
                    ms.erase(ms.begin());
                }
                ms.clear();
                ms.insert(cost[i]);
            }
                
        }
        while(ms.size()>1){
            ans += *(ms.begin());
            ms.erase(ms.begin());
        }

        return ans;
    }
};

// my implementation of best approach
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        if(s.size()==1) return 0;
        int ans=0,maxi=cost[0],curr_sum=cost[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                maxi = max(maxi,cost[i]);
                curr_sum += cost[i];
            }else{
                ans += curr_sum-maxi;
                maxi = curr_sum = cost[i];
            }
                
        }
        ans += curr_sum-maxi;
        return ans;
    }
};

// discuss implementation of best approach
// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/discuss/831502/C%2B%2BJava-O(n)

int minCost(string s, vector<int>& cost) {
    int res = cost[0], max_cost = cost[0];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            res -= max_cost;
            max_cost = 0;
        }
        res += cost[i];
        max_cost = max(max_cost, cost[i]);
    }
    return res - max_cost;
}
