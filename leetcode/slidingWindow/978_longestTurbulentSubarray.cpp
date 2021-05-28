
// need to improve this code :(
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int i=0,j=0,count=0,ans=0,flag=0, n=arr.size();
        while(j<n){
            if(i==j){
                ans = max(ans,count);
                count=1;
                j++;
                if(j<n && arr[i]<arr[j]) flag=0;
                if(j<n && arr[i]>arr[j]) flag=1;
                continue;
            }
            if(arr[i]==arr[j]) {
                i++;continue;
            }
            if(flag==0){
                if(arr[i]<arr[j]){
                    i++;j++;
                    flag=1;
                    count++;
                }else{
                    j--;
                }
            }else{
                if(arr[i]>arr[j]){
                    i++;j++;
                    flag=0;
                    count++;
                }else{
                    j--;
                }
            }
            
        }
        ans = max(ans,count);
        return ans;
        
    }
};
