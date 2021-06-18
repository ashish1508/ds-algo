
// my implementation inspired from discuss O(nlogn) [prefix sum + binarysearch]
// can also be done with 3 pointers in O(n)
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i] = nums[i]+ prefix[i-1];

        for(int i=0;i<n-2;i++){
            int lo=i+1,hi=n-2,mid;
            while(lo<hi){
                mid=lo+(hi-lo)/2;
                if(prefix[mid]-prefix[i] >= prefix[i])
                    hi=mid;
                else 
                    lo=mid+1;
            }
            
            if(prefix[lo]-prefix[i] < prefix[i])
                continue;
            
            int s = lo;
           // you can also make lo=i+1; any thing will work
            hi=n-2;
            
            while(lo<=hi){
                mid=lo+(hi-lo)/2;
                if(prefix[mid]-prefix[i]<=prefix[n-1]-prefix[mid])
                    lo=mid+1;
                else 
                    hi=mid-1;
               
            }
            
            if(prefix[hi]-prefix[i]>prefix[n-1]-prefix[hi])
                continue;
             int e = hi;
            
            if(s>e) continue;
            ans += e-s+1;
            
        }
        return ans%1000000007;
    }
};
