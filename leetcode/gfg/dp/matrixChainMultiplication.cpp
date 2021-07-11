
// aditya verma video is best
class Solution{
public:
    vector<vector<int>> cache;
    int go(int s, int e, int arr[], int N){
        if(s>=e) return 0;
        if(cache[s][e]!=-1) return cache[s][e];
        int local_min = INT_MAX;
        for(int i=s;i<e;i++){
            int left  = go(s,i,arr,N);
            int right = go(i+1,e,arr,N);
            int curr = arr[s-1]*arr[i]*arr[e];
            local_min = min(local_min,left+curr+right);
        }
        
        cache[s][e] = local_min;
        return cache[s][e];
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        cache.resize(N,vector<int>(N,-1));
        return go(1,N-1,arr,N);
    }
};
