

// can improve implementation... time complexity - O(m*nl*log(k))
// Dp solution in discuss
class Solution {
public:

    int check(vector<vector<int>> dungeon, int power){
        
        int r = dungeon.size(),c=dungeon[0].size(),curr_power;
        int pow = power;
        dungeon[0][0] += power;
        pow = dungeon[0][0];
        for(int j=1;j<c;j++){ 
            if(pow<=0){
                dungeon[0][j]=0;
                continue;
            }
            pow += dungeon[0][j];
            dungeon[0][j] = max(pow,0);
        }
        pow = dungeon[0][0];
        for(int i=1;i<r;i++){
            if(pow<=0){
                dungeon[i][0]=0;
                continue;
            }
            pow += dungeon[i][0];
            dungeon[i][0] = max(pow,0);
        }
        
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                curr_power = max(dungeon[i-1][j],dungeon[i][j-1]);
                if(curr_power==0 || curr_power + dungeon[i][j]<=0)
                    dungeon[i][j]=0;
                else{
                    dungeon[i][j] = curr_power + dungeon[i][j];
                }
            }
        }

        if(dungeon[r-1][c-1]>0) return 1;
        return 0;
        
    }
    int calculateMinimumHP(vector<vector<int>> dungeon) {
        // if every element is -1000 and n=200 m=200 then hi 200001
        int lo=1,hi=20001,mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(check(dungeon,mid)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};
