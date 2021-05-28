// my first approach
class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=cardPoints[0];
        for(int i=1;i<n;i++)
            left[i] = left[i-1]+cardPoints[i];
        right[n-1]=cardPoints[n-1];
        for(int i=n-2;i>=0;i--)
            right[i] = cardPoints[i]+right[i+1];
        int ans=left[k-1],curr;

        for(int i=0;i<k-1;i++){
             curr=0;
             curr += left[i];
             curr += right[n-k+i+1];
             ans = max(ans,curr);
        }
        ans = max(ans,right[n-k]);
  
        return ans;
    }
};

// sliding window approach
// youtube video link : https://www.youtube.com/watch?v=U0utLw_vWGM&ab_channel=AlgorithmsMadeEasy
class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(),sum=0,ans=INT_MAX,total=0;
        for(int i=0;i<n;i++)
            total += cardPoints[i];
        int i=0,j=0;
        while(j<=n-k-1){
            sum += cardPoints[j];
            j++;
        }
        ans = min(ans,sum);
        
        while(j<n){
            sum += cardPoints[j];
            sum -= cardPoints[i];
            ans = min(ans,sum);
            i++;
            j++;
        }
        return total-ans;
    }
};
