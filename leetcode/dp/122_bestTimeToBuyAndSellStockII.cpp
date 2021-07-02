// Not a dp problem
// leetcode solution tab is very good

// peak valley approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,buy,sell,ans=0,n=prices.size();
        while(i<n){
            while(i<n-1 && prices[i]>prices[i+1])
                i++;
            buy = prices[i];
            while(i<n-1 && prices[i]<prices[i+1])
                i++;
            sell = prices[i];
            if(sell-buy>0)
                ans += sell-buy;
            i++;
        }
        return ans;
    }
};


// take every small profit 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ans=0,curr=prices[0];
      for(int i=1;i<prices.size();i++){
          if(prices[i]>prices[i-1]){
              ans += prices[i]-prices[i-1];
          }
      }
      return ans;
    }
};
