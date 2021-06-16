class Solution {
public:
    bool check(vector<vector<int>> &grid, int k){
        if(grid[0][0]>k) return false;
        int x,y,n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        queue<pair<int,int>> q;
        vis[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> p = q.front();
            x = p.first; y=p.second;
            if(x==n-1 && y==n-1) return true;
            q.pop();
            for(int i=0;i<4;i++){
                if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]<n && y+dy[i]>=0){
                    if(!vis[x+dx[i]][y+dy[i]] && grid[x+dx[i]][y+dy[i]]<=k){
                        vis[x+dx[i]][y+dy[i]]=1;
                        q.push({x+dx[i],y+dy[i]});
                    }
                }
            }
        }
        return false;
        
    }
    int swimInWater(vector<vector<int>>& grid) {
        int lo=0,hi=2500,mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(!check(grid,mid)) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};
