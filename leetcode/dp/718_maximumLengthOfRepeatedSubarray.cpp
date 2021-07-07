// longest common substriing ending at index-i of nums1 and ending at index-j of nums2
// top down - O(N^2)
class Solution {
public:
    vector<vector<int>> cache;
    int getLength(int i, int j, vector<int> &nums1, vector<int> &nums2){
        if(i==-1 || j==-1) return 0;
        if(cache[i][j]!=-1) return cache[i][j];
        int ans;
        if(nums1[i]==nums2[j])  ans = 1 + getLength(i-1,j-1,nums1,nums2);
        else ans=0;
        cache[i][j] = ans;
        return cache[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        cache.resize(nums1.size(),vector<int>(nums2.size(),-1));
        int ans=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                ans = max(ans,getLength(i,j,nums1,nums2));
            }
        }
        return ans;
    }
};

// binary search 0(n^2 logn) TLE
class Solution {
public: 
    int check(vector<int> &nums1, vector<int> &nums2, int k){
        int coun,j,l,m;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                coun=0;
                m=i;
                l=j;
                while(m<nums1.size() && l<nums2.size() && coun<k){
                    if(nums1[m]!=nums2[l]) break;
                    coun++;
                    l++;m++;
                }
                if(coun==k) return 1;
            }
        }
        return 0;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int lo=0,hi=min(nums1.size(),nums2.size()),mid;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(check(nums1,nums2,mid)) lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};
