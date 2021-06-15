// same as 1482,875,1760,1011 
class Solution {
public:
    int check(vector<int> &nums, int div){
        int count=0;
        for(int i=0;i<nums.size();i++)
                count += ceil(double(nums[i])/div);
        return count;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1,hi=1000000,mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(check(nums,mid)> threshold) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};
