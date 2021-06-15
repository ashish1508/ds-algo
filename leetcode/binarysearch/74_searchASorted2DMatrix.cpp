class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size(),lo=0,hi=r*c-1,mid,i,j;
        while(lo<=hi){
            mid =lo+(hi-lo)/2;
            i = mid/c;
            j = mid%c;
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};
