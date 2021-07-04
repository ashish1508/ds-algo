// approach : when we remove an element all the even elements to the left of the element become odd elements and keep prefix sum of odd and even elements
// my first implementation (very bad) O(n) space
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<long long> odd(n,0);
        vector<long long> even(n,0);
        long long odd_sum=0,even_sum=0;
        for(int i=0;i<n;i++){
            if(i%2){
                odd_sum += nums[i];
                odd[i] = odd_sum;
                even[i] = even_sum;
            }else{
                even_sum += nums[i];
                even[i] += even_sum;
                odd[i] = odd_sum;
            }
        }
        int ans=0,before=0,after=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(odd_sum-odd[i]==even_sum-even[i])
                    ans++;
                continue;
            }
            if(i==n-1){
                if(odd[i-1]==even[i-1])
                    ans++;
                continue;
            }
            if(odd[i-1]+even_sum-even[i] == even[i-1]+odd_sum -odd[i]) ans++;
            
        }
        return ans;
    }
};

// Better implementation from discuss


class Solution {
    public int waysToMakeFair(int[] nums) {
        int res = 0;
        int n =nums.length;
        int righteven = 0, rightodd = 0;
        
        for(int i=0; i<n; ++i) {
            if(i%2 == 0) righteven += nums[i];
            else rightodd += nums[i];
        }
        
        int lefteven = 0, leftodd = 0;
        for(int i=0; i<n; ++i) {
            
            if(i%2 == 0) {
                righteven -= nums[i];
            } else {
                rightodd -= nums[i];
            }
            
            if(lefteven + rightodd == leftodd + righteven)
                ++res;
            
            if(i%2== 0) {
                lefteven += nums[i];
            } else {
                leftodd += nums[i];
            }
        }
        
        return res;
    }
    
}


