
// approach :  go(i,N) => starting at i number and length n
class Solution{
	public:
	vector<vector<int>> keypad {{8},{2,4},{1,3,5},{2,6},{1,5,7},{2,4,6,8},{3,5,9},{4,8},{0,5,7,9},{6,8}} ;
	vector<vector<long long>> cache;
	long long go(int i, int N){
	    if(N==1) return 1;
	    if(cache[i][N]!=-1) return cache[i][N];
	    long long local_ans = go(i,N-1);
	    for(int j=0;j<keypad[i].size();j++)
	        local_ans += go(keypad[i][j],N-1);
	    cache[i][N] = local_ans; 
	    return cache[i][N];
	}
	
	long long getCount(int N)
	{
		// Your code goes here
		cache.resize(10,vector<long long>(N+1,-1));
		long long ans = 0;
		for(int i=0;i<10;i++)
		    ans += go(i,N);
		return ans;
	}

};
