class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,c=1,j;
        for(j=1;j<nums.size();j++){
            if(nums[j]==nums[i]){
                if(c<3){
                    nums[i+1]=nums[j];
                    c++;   
                } 
            }else{
                i= i+c;
                nums[i]=nums[j];
                c=1;
            } 
        }
        return i+c;
    }
};
