// same approach as 1760 leetcode solution
class Solution {
public:
    int check(vector<int> &piles, int k, int h){
        int count=0;
        for(int i=0;i<piles.size();i++)
            count += ceil(double(piles[i])/k);
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1,hi=INT_MAX,mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(check(piles,mid,h)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};
