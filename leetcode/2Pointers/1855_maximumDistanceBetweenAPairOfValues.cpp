class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=nums1.size()-1,j=nums2.size()-1,ans=0;
        while(i>=0 && j>=0){
            while(j>=0 && nums2[j]<nums1[i])
                j--;
            if(j>=0)
                ans = max(ans,j-i);
            i--;  
        }
        return ans;
        
    }
};
