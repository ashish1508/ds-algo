// same solution approach as 875,1760 leetcode solutions
class Solution {
public:
    int check(vector<int> &bloomDay, int days, int bouquets, int adj){
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days) count++;
            else{
                bouquets -= (count/adj);
                count=0;
            }
        }
        bouquets -= (count/adj);
        return bouquets<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k>bloomDay.size()) return -1;
        int lo=1,hi=INT_MAX,mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(check(bloomDay,mid,m,k)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};
