// my first correct implementation
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int j,k,l,n=nums.size(),sum;
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            while(i>0 && i<n-3 && nums[i]==nums[i-1])i++;
            j=i+1;
            while(j<n-2){
                k=j+1;
                l=n-1;
                while(k<l){
                    sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        ret.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[k]==nums[k+1])k++;
                        k++;
                    }else if(sum<target){
                        k++;
                    }else if(sum>target){
                        l--;
                    }
               }
               j++;
               while(j<n-2 && nums[j]==nums[j-1]) j++;
           }
        }
        return ret;
    }
};

// better implementation from comments under solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int j,k,l,n=nums.size(),sum;
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                k=j+1;
                l=n-1;
                while(k<l){
                    
                    sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        ret.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[k]==nums[k+1])k++;
                        k++;
                    }else if(sum<target){
                        k++;
                    }else if(sum>target){
                        l--;
                    }
                
               }

          }
       }
       return ret;
    }
};
