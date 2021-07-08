class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    vector<int> cache {vector<int>(10001,-1)};
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==0) return 0;
        if(n==1) return arr[0];
        if(cache[n]!=-1) return cache[n];
        cache[n] = max(FindMaxSum(arr,n-1),arr[n-1]+FindMaxSum(arr,n-2));
        return cache[n];
    }
};
