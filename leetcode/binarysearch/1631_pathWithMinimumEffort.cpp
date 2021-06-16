// Same as 778 ....can be solved with dijkstra solution in discuss
class Solution {
public:
    bool check(vector<vector<int>> &grid, int k){
        
        int x,y,r=grid.size(),c=grid[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        queue<pair<int,int>> q;
        vis[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> p = q.front();
            x = p.first; y=p.second;
            if(x==r-1 && y==c-1) return true;
            q.pop();
            for(int i=0;i<4;i++){
                if(x+dx[i]>=0 && x+dx[i]<r && y+dy[i]<c && y+dy[i]>=0){
                    if(!vis[x+dx[i]][y+dy[i]] && abs(grid[x+dx[i]][y+dy[i]]-grid[x][y])<=k){
                        vis[x+dx[i]][y+dy[i]]=1;
                        q.push({x+dx[i],y+dy[i]});
                    }
                }
            }
        }
        return false;
        
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo=0,hi=1000000,mid;
        
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(!check(heights,mid)) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};
