
// top down
class Solution{
    public:
    /*You are required to complete below method */
    long  long int  mod  = 1000000007;
    long long int CPS(int s, int e, string &st, vector<vector<long long>> &cache){
        if(s>e) return 0;
        if(s==e) return 1;
        if(cache[s][e]!=-1) return cache[s][e];
        long long int ans;
        if(st[s]==st[e]) 
            ans = ( 1 + CPS(s,e-1,st,cache)%mod + CPS(s+1,e,st,cache)%mod)%mod;
        else
            ans = (mod + CPS(s+1,e,st,cache)%mod + CPS(s,e-1,st,cache)%mod - CPS(s+1,e-1,st,cache)%mod)%mod; // why adding mod ? - to prevent value from going to negative ..can see in comments
            
        
        cache[s][e] = ans;
        return cache[s][e];
    }
    long long int  countPS(string str)
    {
       //Your code here
       vector<vector<long long>> cache;
       cache.resize(str.size(),vector<long long>(str.size(),-1));
       return CPS(0, str.size()-1, str,cache);
    }
     
};
