// approach :  count h-1  and count h-2 ..possibilities h-1,h-1 and h-1,h-2 and h-2,h-1
class Solution {
  public:
    long long mod = 1000000007;
    vector<long long > cache{vector<long long>(1001,-1)};
    long long int countBT(int h) { 
        if(h==0 || h==1) return 1;
        if(cache[h]!=-1) return cache[h];
        long long  f  = countBT(h-1);
        long long  s = countBT(h-2);
        cache[h] =  (f*f + 2*f*s)%mod;
        return cache[h];
    }
};
