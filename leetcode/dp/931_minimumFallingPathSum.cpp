// saw the approach before in rachit jain video
// top down with memoization
class Solution {
public:
    vector<vector<int>> cache;
    int getMinPath(int x,int y, vector<vector<int>> &matrix){
        if(y<0 || y==matrix[0].size()) return INT_MAX;
        if(x==matrix.size()-1) return matrix[x][y];
        if(cache[x][y]!=INT_MAX) return cache[x][y];
        int p1 = getMinPath(x+1,y,matrix);
        int p2 = getMinPath(x+1,y-1,matrix);
        int p3 = getMinPath(x+1,y+1,matrix);
        cache[x][y] = min({p1,p2,p3})+matrix[x][y];
         return cache[x][y];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        cache.resize(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        for(int i=0;i<matrix[0].size();i++){
            ans = min(ans,getMinPath(0,i,matrix));
        }
        return ans;
    }
};

// bottom up
class Solution {
public: 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX, r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> cache;
        cache.resize(r,vector<int>(c,INT_MAX));
        for(int i=r-1;i>=0;i--){
            for(int j=0;j<c;j++){
                if(i==r-1){
                    cache[i][j] = matrix[i][j];
                    continue;
                }
                int p1 = j-1<0 ? INT_MAX : cache[i+1][j-1];
                int p2 = j+1==c ? INT_MAX : cache[i+1][j+1];
                int p3 = cache[i+1][j];
                cache[i][j] = min({p1,p2,p3})+matrix[i][j];
            }
        }
        for(int j=0;j<c;j++){
            ans = min(ans,cache[0][j]);
        }
        return ans;
    }
};
