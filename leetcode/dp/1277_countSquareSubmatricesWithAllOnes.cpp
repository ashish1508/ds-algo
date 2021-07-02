// leetcode discuss https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/643429/Python-DP-Solution-%2B-Thinking-Process-Diagrams-(O(mn)-runtime-O(1)-space)
// top down 
class Solution {
public:
    
    vector<vector<int>> cache;
    int getSquares(int r,int c, vector<vector<int>> &matrix){
        if(r<0 || r==matrix.size() || c<0 || c==matrix[0].size() ||matrix[r][c]==0 ) return 0;
        if(cache[r][c]!=-1) return cache[r][c];
        
        if(r==0 || c==0){
            return matrix[r][c];
        } 
        int a = getSquares(r-1,c-1,matrix);
        int b = getSquares(r,c-1,matrix);
        int d = getSquares(r-1,c,matrix);
        cache[r][c] =  min({a,b,d}) + 1;
        return cache[r][c];
        
    }
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size(),c=matrix[0].size();
        cache.resize(r,vector<int>(c,-1));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j]) {
                    int sz = getSquares(i,j,matrix); 
                    ans += sz;
                }
            }
        }
        return ans;
    }
};

// bottom up
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size(),c=matrix[0].size();
        int ans = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j]) {
                    if(i==0 || j==0) ans++;
                    else{
                        matrix[i][j] = min({matrix[i-1][j-1],matrix[i][j-1],matrix[i-1][j]})+1;
                        ans += matrix[i][j];
                    }
                }
            }
        }
        return ans;
    }
};
