int subsetSum(int n, int sum, vector<int> &A, vector<vector<int>> &cache){
    if(n==0 && sum==0) return 1;
    if(n==0) return 0;
    if(cache[n][sum]!=-1) return cache[n][sum];
    int without = subsetSum(n-1,sum,A,cache);
    int with = sum-A[n-1]>=0 ? subsetSum(n-1,sum-A[n-1],A,cache) : 0;
    cache[n][sum] = with || without;
    return cache[n][sum];
}

int Solution::solve(vector<int> &A) {
    int n = A.size(),ans,sum=0;
    for(auto num : A)
        sum += num;
    for(int val=sum/2;val>=0;val--){
        vector<vector<int>> cache(n+1,vector<int>(val+1,-1));
        if(subsetSum(n,val,A,cache)==1){
            ans = abs(val-(sum-val));
            break;
        }
    }
    return ans;
}
