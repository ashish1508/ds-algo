class Solution {
public:
    bool isSafe(int r, int c, vector<string> &path){
        bool safe=true;
        for(int i=r-1;i>=0;i--){
            if(path[i][c]=='Q'){
                safe=false;
                break;
            }
        }
        for(int i=r-1,j=c+1;i>=0 && j<path[0].size();i--,j++){
            if(path[i][j]=='Q'){
                safe = false;
                break;
            }
        }
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(path[i][j]=='Q'){
                safe = false;
                break;
            }
        }
        return safe;
    }
    void nQueens(int s, vector<string> &path, vector<vector<string>> &ans){
        if(s==path.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<path[0].size();i++){
            if(isSafe(s,i,path)){
                path[s][i] = 'Q';
                nQueens(s+1,path,ans);
                path[s][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s = "";
        s.append(n,'.');
        vector<string> path(n,s);
        nQueens(0,path,ans);
        return ans;
    }
};
