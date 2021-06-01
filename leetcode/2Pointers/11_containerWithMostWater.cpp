// idea : https://medium.com/swlh/two-pointer-technique-solving-array-problems-at-light-speed-56a77ee83d16

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,ans=0;
        while(i<j){
            if(height[i]<=height[j]){
                ans = max(ans,height[i]*(j-i));
                i++;
            }else{
                ans = max(ans,height[j]*(j-i));
                j--;
            }
        }
        return ans;
    }
};
