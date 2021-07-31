class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int> um;
        int ans=0;
        for(int i=0;i<n;i++){
            ans += um[k-arr[i]];
            um[arr[i]]++;
        }
        return ans;
    }
};
