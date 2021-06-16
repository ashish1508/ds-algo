
// my first implementation -- high time complexity. O(n^2 * nlogn)
class Solution {
public:
    int lessThanOrEqual(vector<vector<int>> &matrix,int vi,int vj){
        int val=matrix[vi][vj], n=matrix.size(), lo,hi=n-1,mid,i=0,ans=0;
        while(i<n){
            lo=0;
            while(lo<=hi){
                mid=lo+(hi-lo)/2;
                if(matrix[i][mid]<=val) lo=mid+1;
                else hi=mid-1;
            }
            
            ans += hi+1;  
            i++;
        }
        
        return ans;
        
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(lessThanOrEqual(matrix,i,j)>=k){
                    ans = min(ans,matrix[i][j]);
                }
            }
        }
        return ans;
    }
};
// Binary search over range -- time complexity O(log(matrix[n-1][n-1]-matrix[0][0])*nlogn) 
class Solution {
public:
    int lessThanOrEqual(vector<vector<int>> &matrix,int val){
        int n=matrix.size(), lo,hi=n-1,mid,i=0,ans=0;
        while(i<n){
            lo=0;
            while(lo<=hi){
                mid=lo+(hi-lo)/2;
                if(matrix[i][mid]<=val) lo=mid+1;
                else hi=mid-1;
            } 
            ans += hi+1;  
            i++;
        }
        
        return ans;
        
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),lo=matrix[0][0],hi=matrix[n-1][n-1],mid;

        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(lessThanOrEqual(matrix,mid)>=k) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};
// other implementation  with priority queue in discuss
