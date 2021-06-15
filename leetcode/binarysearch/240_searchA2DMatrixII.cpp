// find element greater than or equal to target in every row and dont change high index
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size(),lo=0,hi=c-1,mid,i=0;
        while(i<r){
            lo=0;
            while(lo<hi){
                mid=lo+(hi-lo)/2;
                if(matrix[i][mid]<target) lo=mid+1;
                else hi=mid;
            }
            if(matrix[i][lo]==target) return true;
            i++;
        }
        return false;
    }
};
