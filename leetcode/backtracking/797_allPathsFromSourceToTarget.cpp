
class Solution {
public:
    void getAllPaths(vector<vector<int>> &graph, vector<int> &path, int node, vector<vector<int>> &ans){
        if(node==graph.size()-1){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<graph[node].size();i++){
            path.push_back(graph[node][i]);
            getAllPaths(graph,path,graph[node][i],ans);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        getAllPaths(graph,path,0,ans);
        return ans;
    }
};
