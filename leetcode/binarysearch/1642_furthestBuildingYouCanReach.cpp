// my first implementation  : nlogn approach 
class Solution {
public:
    bool canReach(vector<int> &heights, int hi, int bricks, int ladders){
        vector<int> vec;
        for(int i=1;i<=hi;i++){
            if(heights[i]>heights[i-1]){
                vec.push_back(heights[i]-heights[i-1]);
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            if(bricks>=vec[i]){
                bricks -= vec[i];
                continue;
            }
            if(ladders){
                ladders--;
                continue;
            }
            return false;
        }
        return true;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int lo=0,n=heights.size(),hi=n-1,mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(canReach(heights,mid,bricks,ladders)) lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};

// other approaches using priority queue available in discuss
