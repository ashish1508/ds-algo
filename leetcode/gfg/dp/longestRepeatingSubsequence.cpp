
// top down
class Solution {
	public:
	    vector<vector<int>> cache;
	    int LRS(int i, int j, string &st){
	        if(i==-1 || j==-1) return 0;
	        if(cache[i][j]!=-1) return cache[i][j];
	        if(st[i]==st[j]) return 1+LRS(i-1,j-1,st);
	        int f = LRS(i,j-1,st);
	        int s = (j != i-1) ? LRS(i-1,j,st) : 0;
	        cache[i][j] = max(f,s);
	        return cache[i][j];
	    }
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    cache.resize(n,vector<int>(n,-1));
		    return LRS(n-1,n-2,str);
		}

};
