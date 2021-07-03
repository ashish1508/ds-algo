
// initial recursiion approach (TLE)  [own learning --> (imp : recursive functions should return a value for it to be memoized otherwise we cannot do memoization)]
// should not use global variables to set answer in dp problems in top down
class Solution {
public:

    int final_ans=0;
    //vector<vector<int>> cache;
    void getMaxSum(int s,int sum,int k, vector<int> &arr){
        if(s==arr.size()){
            final_ans = max(final_ans,sum);
            return;
        }
        // if(cache[s]!=-1) return cache[s];
        int local_max=0,ans;
        int e = s+k < arr.size() ? s+k : arr.size();
        for(int i=s;i<e;i++){
            local_max = max(local_max,arr[i]);
            ans = local_max*(i-s+1);
            getMaxSum(i+1,sum+ans,k,arr);
            
        }
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //cache.resize(arr.size(), vector<int>());
        getMaxSum(0,0,k,arr);
        return final_ans;
    }
};

// recursion which can be memoized
class Solution {
public: 
    int getMaxSum(int s, int k, vector<int> &arr){
        if(s==arr.size()){
            return 0;
        }
        int local_max=0,sum_max=0,local_sum;
        int e = s+k < arr.size() ? s+k : arr.size();
        for(int i=s;i<e;i++){
            local_max = max(local_max,arr[i]);
            local_sum = local_max*(i-s+1);
            sum_max = max(sum_max,getMaxSum(i+1,k,arr)+local_sum);
            
        }
        return sum_max;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        cache.resize(arr.size(),-1);
        return getMaxSum(0,k,arr);  
    }
};

// top down recursion with memoization
class Solution {
public:

    
    vector<int> cache; 
    int getMaxSum(int s, int k, vector<int> &arr){
        if(s==arr.size()){
            return 0;
        }
        if(cache[s]!=-1) return cache[s];
        int local_max=0,sum_max=0,local_sum;
        int e = s+k < arr.size() ? s+k : arr.size();
        for(int i=s;i<e;i++){
            local_max = max(local_max,arr[i]);
            local_sum = local_max*(i-s+1);
            sum_max = max(sum_max,getMaxSum(i+1,k,arr)+local_sum);
            
        }
        cache[s] = sum_max;
        return cache[s];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        cache.resize(arr.size(),-1);
        return getMaxSum(0,k,arr);  
    }
};

// bottom up
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> cache; 
        cache.resize(arr.size()+1,0);
        int n = arr.size(),sum_max = INT_MIN,local_max,local_sum;
        for(int i=n-1;i>=0;i--){;
            int e = i+k < arr.size() ? i+k : arr.size();  
            local_max=INT_MIN;
            for(int j=i;j<e;j++){
                local_max = max(local_max,arr[j]);
                local_sum = local_max*(j-i+1);
                sum_max = max(sum_max,cache[j+1]+local_sum);
            }
            cache[i] = sum_max;
        }
        return cache[0];
    }
};
