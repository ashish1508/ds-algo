
// O(nlogn) using sort + fenwick tree https://leetcode.com/problems/count-number-of-teams/discuss/554795/C%2B%2BJava-O(n-*-n)-and-O(n-log-n)
// my first implementation O(n^2)
class Solution {
public:
    
    int numTeams(vector<int>& rating) {
        vector<int> greaterLeft(rating.size());
        vector<int> lesserLeft(rating.size());
        vector<int> greaterRight(rating.size());
        vector<int> lesserRight(rating.size());
        int less_count,high_count;
        for(int i=0;i<rating.size();i++){
            less_count=0;
            high_count=0;
            for(int j=i-1;j>=0;j--){
                if(rating[j]<rating[i])
                    less_count++;
                if(rating[j]>rating[i])
                    high_count++;
            }
            lesserLeft[i] = less_count;
            greaterLeft[i] = high_count; 
        }
        for(int i=0;i<rating.size();i++){
            less_count=0;
            high_count=0;
            for(int j=i+1;j<rating.size();j++){
                if(rating[j]<rating[i])
                    less_count++;
                if(rating[j]>rating[i])
                    high_count++;
            }
            lesserRight[i] = less_count;
            greaterRight[i] = high_count; 
        }
        
        int ans=0;
        for(int i=0;i<rating.size();i++){
            ans += lesserLeft[i]*greaterRight[i];
            ans += greaterLeft[i]*lesserRight[i];
        }
        return ans;
    }
};

//better implementation O(n^2)
class Solution {
public:
    
    int numTeams(vector<int>& rating) {

        int less_left,high_left,less_right,high_right,ans=0;
        for(int i=0;i<rating.size();i++){
            less_left=high_left=less_right=high_right=0;
            for(int j=i-1;j>=0;j--){
                if(rating[j]<rating[i])
                    less_left++;
                if(rating[j]>rating[i])
                    high_left++;
            }
            for(int j=i+1;j<rating.size();j++){
                if(rating[j]<rating[i])
                    less_right++;
                if(rating[j]>rating[i])
                    high_right++;
            }
            ans = ans + less_left*high_right + high_left*less_right;
        }
        return ans;
    }
};
