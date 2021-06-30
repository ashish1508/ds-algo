class Solution {
public:
    void wordSearch(int x, int y, string &path, vector<vector<int>> &vis, vector<vector<char>> &board, string &word, bool &ans){  
        
        if(board[x][y]==word[path.size()]){
            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0};
            vis[x][y]=1;
            path.push_back(board[x][y]);
            // if this condition is just at the top of the function we will miss some corner case as 1*1 board so kept it here        
            if(path.size()==word.size()){
                ans = true;
                return;
            }
            for(int i=0;i<4;i++){
                if(x+dx[i]<0 || x+dx[i]>=board.size() || y+dy[i]<0 || y+dy[i]>=board[0].size()) continue;
                if(!vis[x+dx[i]][y+dy[i]])
                    wordSearch(x+dx[i],y+dy[i],path,vis,board,word,ans);
            }
            path.pop_back();
            vis[x][y]=0;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        string path="";
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        bool ans=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                wordSearch(i,j,path,vis,board,word,ans);
            }
        }
        return ans;
    }
};
