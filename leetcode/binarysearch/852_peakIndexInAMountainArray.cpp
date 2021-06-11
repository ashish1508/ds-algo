class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=0,hi=arr.size()-1,mid,ans;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                ans=mid;
                break;
            }
            else if(arr[mid-1]>arr[mid]) hi=mid;
            else if(arr[mid]<arr[mid+1]) lo=mid;
        }
        return ans;
    }
};
