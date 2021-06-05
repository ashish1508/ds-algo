// my first implementation .. can be made easy
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int b1=-1,p=-1,ans=0,i;
        for(i=0;i<arr.size()-1;i++){
          // find peak
          if(i>0 && arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                p = i;
          }
          //find base1
          if(b1==-1 && arr[i]<arr[i+1]){
               b1=i; 
          }   
          // if base2 found
          if(b1!=-1 && p!=-1 && arr[i]<=arr[i+1]){
              ans = max(ans,i-b1+1);
              p=-1;
              b1=-1;
              i--;
          } 
          // removing base1
          if(arr[i] == arr[i+1])
              b1=-1;

        } 
        if(b1!=-1 && p!=-1 && arr[i-1]>arr[i]){
            ans = max(ans,i-b1+1);
        } 
        return ans;
    }
};

// easy implementation from leetcode discuss
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int count,ans=0;
        for(int i=1;i<arr.size()-1;i++){
          //find peak
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                count=3;
                int j=i-1;
                int k=i+1;
                // go left
                while(j>0 && arr[j-1]<arr[j]){
                    count++;j--;
                } 
                // go right
                while(k<arr.size()-1 && arr[k]>arr[k+1]){
                    count++;k++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
