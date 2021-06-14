// O(nlogn) without extra space
// see leetcode solutions tab for other approaches 
// solution approach on leetcode discuss : https://leetcode.com/problems/find-the-duplicate-number/solution/256055
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
            int lo=1,hi=nums.size()-1,mid;
            while(lo<hi){
                cout<<lo<<" "<<hi<<endl;
                mid=lo+(hi-lo)/2;
                int leq=0,geq=0;
                for(auto num:nums){
                    if(num>=mid) geq++;
                    if(num<=mid) leq++;
                }
                if(leq>mid && geq>nums.size()-mid) return mid;
                // number may or may not be present in the array..so less than or equal to 
                if(leq<=mid) lo=mid+1;
                else hi=mid-1;
            }
            return lo;
    }
};
