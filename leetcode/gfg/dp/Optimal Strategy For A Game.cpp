
// approach : opponent always tries to minimize the maximum amount we can get
int getMaxAmount(int s, int e, int arr[], vector<vector<int>> &cache){
    if(s>e) return 0;
    //if(s==e) return arr[s];
    if(cache[s][e]!=-1) return cache[s][e];
    int first = arr[s] + min(getMaxAmount(s+2,e,arr,cache),getMaxAmount(s+1,e-1,arr,cache));
    int second = arr[e] + min(getMaxAmount(s,e-2,arr,cache),getMaxAmount(s+1,e-1,arr,cache));
    cache[s][e] = first>second ? first : second;
    //cout<<s<<" "<<e<<" "<<cache[s][e]<<endl;
    return cache[s][e];
    
}

//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n) 
{
    // Your code here
    vector<vector<int>> cache(n,vector<int>(n,-1));
    return getMaxAmount(0,n-1,arr,cache);
}
