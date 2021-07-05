
// O(n^2) with dp
//  O(n)-time  O(1)-space
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return 0;
        int max_reach = nums[0],min_steps=1, curr_max_reach=nums[0];
        for(int i=1;i<n;i++){
            if(i<=max_reach){
                curr_max_reach = max(curr_max_reach,i+nums[i]);
            }else if(i>max_reach){
                min_steps++;
                max_reach = curr_max_reach;
                curr_max_reach = i+nums[i];
            }
            if(i>max_reach) return -1;
        }
        return min_steps;
    }
};
