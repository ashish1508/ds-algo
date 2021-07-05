class Solution
{
    public:
    //Function to find the maximum number of cuts.
    vector<int> cache;
    int getCuts(int n, vector<int> &vec){
        
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        if(cache[n]!=-1) return cache[n];
        int local_max=INT_MIN,curr_max;
        for(int i=0;i<3;i++){
            curr_max = getCuts(n-vec[i],vec);
            if(curr_max!=INT_MIN){
                local_max = max(local_max,1+curr_max);
            }
        }
        cache[n] = local_max;
        return cache[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        cache.resize(n+1,-1);
        vector<int> vec({x,y,z});
        getCuts(n,vec);
        if(cache[n]==INT_MIN) return 0;
        return cache[n];
        
    }
};
