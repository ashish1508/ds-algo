// approach nCr -> n-1Cr-1 + nCr-1
// n-1Cr-1 => number of combinations where nth number is used
// n-1Cr => number of combinations where nth number is not used
// top down
class Solution{
public:
long long mod = 1000000007;
    vector<vector<int>> cache {vector<vector<int>>(1001,vector<int>(801,-1))};
    int nCr(int n, int r){
        // code here
        if(r>n) return 0;
        if(r==n || r==0) return 1;
        if(cache[n][r]!=-1) return cache[n][r];
        cache[n][r] = (nCr(n-1,r-1)%mod + nCr(n-1,r)%mod)%mod;
        return cache[n][r];
    }
};
