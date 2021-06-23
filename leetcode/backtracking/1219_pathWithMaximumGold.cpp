
// approach 1 : doing backtract things in the function
class Solution {
public:
    
    void dfs(int x,int y, vector<vector<int>> &grid, vector<vector<int>> &vis, int &curr_ans, int &ans){
            
            if(grid[x][y]==0) return;
        
            vis[x][y]=1;
            curr_ans += grid[x][y];
            ans = max(ans,curr_ans);
        
            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0};
        
            for(int i=0;i<4;i++){
                if(x+dx[i]<0 || x+dx[i]>=grid.size() || y+dy[i]<0 || y+dy[i]>=grid[0].size()) continue;
                if(!vis[x+dx[i]][y+dy[i]] && grid[x+dx[i]][y+dy[i]]){
                    dfs(x+dx[i],y+dy[i],grid,vis,curr_ans,ans);
                }
            }
            curr_ans -= grid[x][y];
            vis[x][y]=0;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> q;
        int ans=0,curr_ans=0,x,y;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]){
                    dfs(i,j,grid,vis,curr_ans,ans);
                }
            }
        }
        return ans;
    }
};

// approach 2 : doing backtrack things inside for loop

class Solution {
public:
    
    void dfs(int x,int y, vector<vector<int>> &grid, vector<vector<int>> &vis, int &curr_ans, int &ans){
            
            if(grid[x][y]==0) return;
        
        
            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0};
        
            for(int i=0;i<4;i++){
                if(x+dx[i]<0 || x+dx[i]>=grid.size() || y+dy[i]<0 || y+dy[i]>=grid[0].size()) continue;
                if(!vis[x+dx[i]][y+dy[i]] && grid[x+dx[i]][y+dy[i]]){
                    vis[x+dx[i]][y+dy[i]]=1;
                    curr_ans += grid[x+dx[i]][y+dy[i]];
                    ans = max(ans,curr_ans);
                    dfs(x+dx[i],y+dy[i],grid,vis,curr_ans,ans);
                    curr_ans -= grid[x+dx[i]][y+dy[i]];
                    vis[x+dx[i]][y+dy[i]]=0;
                }
            }
            

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> q;
        int ans=0,curr_ans=0,x,y;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]){
                    vis[i][j]=1;
                    curr_ans += grid[i][j];
                    ans = max(ans,curr_ans);
                    dfs(i,j,grid,vis,curr_ans,ans);
                    curr_ans -= grid[i][j];
                    vis[i][j]=0;
                }
            }
        }
        return ans;
    }
};
