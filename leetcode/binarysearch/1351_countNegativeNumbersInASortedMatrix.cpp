// find first negative number in each row using binary search
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int lo=0,hi=grid[0].size(),ans=0,i=0,r=grid.size(),mid;
        while(i<r){
            lo=0;
            while(lo<hi){
                mid = lo+(hi-lo)/2;
                if(grid[i][mid]>=0) lo=mid+1;
                else hi=mid;
            }
            ans += grid[0].size()-lo;
            i++;
        }
        return ans;
    }
};
