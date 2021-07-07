
// top down
int LCS3(int i, int j, int k, string &A, string &B, string &C, vector<vector<vector<int>>> &cache){
    if(i==0 || j==0 || k==0) return 0;
    
    if(cache[i][j][k]!=-1) return cache[i][j][k];
    
    if(A[i-1]==B[j-1] && B[j-1]==C[k-1]){
        cache[i][j][k] = 1+LCS3(i-1,j-1,k-1,A,B,C,cache);
        return cache[i][j][k];
    }
    int local_max=0;
    local_max = max({LCS3(i-1,j,k,A,B,C,cache),LCS3(i,j-1,k,A,B,C,cache),LCS3(i,j,k-1,A,B,C,cache)});
    cache[i][j][k] = local_max;
    return cache[i][j][k];
    
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> cache(101,vector<vector<int>>(101,vector<int>(101,-1)));
    return LCS3(n1,n2,n3,A,B,C,cache);
}
