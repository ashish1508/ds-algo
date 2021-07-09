// dp is overkill -- O(n^2) --- try all possible pairings from i-1 to j for ith element
// greedy O(nlogn) --- pair ith element with (i-1)th element and move on
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
       sort(arr,arr+N);
       int j,sum=0;
       for(int i=N-1;i>=1;i--){
           if(arr[i]-arr[i-1]<K){
               sum += arr[i]+arr[i-1];
               i--;
           }
       }
       return sum;
    }
};
