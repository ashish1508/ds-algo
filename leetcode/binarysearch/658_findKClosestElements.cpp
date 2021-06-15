// my implementation O(logN+k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo=0,n=arr.size(),hi=n-1,mid,ind=-1;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(arr[mid]<x) lo=mid+1;
            else hi=mid;
        }
        vector<int> vec;
        int i=lo-1,j=lo,lval,rval;
        while(k--){
            lval = i>=0 ? abs(arr[i]-x) : INT_MAX;
            rval = j<n ? abs(arr[j]-x) : INT_MAX;
            if(lval==INT_MAX && rval==INT_MAX) continue;
            if(lval<=rval){
                i--;
            }else{
                j++;
            }
        }
        i++;j--;
        while(i<=j){
            vec.push_back(arr[i]);
            i++;
        }
        return vec;
    }
};

//  VVIMP leetcode solution implementation O(log(n-k)+k)
