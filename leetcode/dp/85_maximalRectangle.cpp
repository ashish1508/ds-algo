// O(n^2) uses largest rectangle in histogram in 1d subarray : tushar roy video is also good
// approach : fix columns and problem transforms into 1d array
// O(n^3) solution
class Solution {
public:
    int getMaxOnes(int c1, int c2, vector<vector<int>> &grid){
        int count = c2-c1+1;
        int rows=0,ans=0;
        for(int i=0;i<grid.size();i++){
            int hi = grid[i][c2];
            int lo = c1==0 ? 0 : grid[i][c1-1];
            if(hi-lo == count)
                rows++;
            else
                rows=0;
            ans = max(ans,rows*count);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = 0;
        vector<vector<int>> grid(r,vector<int>(c,-1));
        for(int i=0;i<r;i++){
            grid[i][0] = matrix[i][0]-'0';
        }
        for(int i=0;i<r;i++){
            for(int j=1;j<c;j++){
                grid[i][j] = matrix[i][j]-'0' + grid[i][j-1];
            }
        }
        for(int c1=0;c1<c;c1++){
            for(int c2=c1;c2<c;c2++){
                ans = max(ans,getMaxOnes(c1,c2,grid));
            }
        }
        return ans;
    }
};
