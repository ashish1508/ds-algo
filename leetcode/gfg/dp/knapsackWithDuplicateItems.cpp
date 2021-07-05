// top down
class Solution{
public:
    vector<int> cache;
    int go(int N, int W, int val[], int wt[]){
        if(W==0) return 0;
        if(cache[W]!=-1) return cache[W];
        int local_max=INT_MIN, curr_max;
        for(int i=0;i<N;i++){
            if(W-wt[i]>=0)
                local_max = max(local_max,val[i]+go(N,W-wt[i],val,wt));
            else
                local_max = max(local_max,0);
        }
        cache[W] = local_max;
        return cache[W];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        cache.resize(W+1,-1);
        if(go(N,W,val,wt)==INT_MIN) return 0;
        return cache[W];
        
    }
};
