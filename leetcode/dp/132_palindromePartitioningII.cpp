// approach : store all palindromes in cache ... store all partitions in cache ...O(n^3) complexity
// better solutiions available in leetcode solutions tab..please have a look at it
class Solution {
public:
    vector<vector<int>> palcache;
    vector<vector<int>> partcache;
    int getPartitions(int s, int e, string &str){
        if(s>e) return -1;
        if(s==e) return 0;
        if(partcache[s][e]!=-1) return partcache[s][e];
        int local_min = e-s;
        for(int i=s;i<=e;i++){
            if(palcache[s][i]){
                local_min = min(local_min, 1+getPartitions(i+1,e,str));
            }
        }
        
        partcache[s][e] = local_min;
        return partcache[s][e];
    }
    int minCut(string str) {
        int n = str.size(); 
        palcache.resize(n,vector<int>(n,0));
        partcache.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
            palcache[i][i]=1;
        for(int i=0;i<n-1;i++){
            if(str[i]==str[i+1]){
                palcache[i][i+1]=1;
            }
        }
        for(int gap=2;gap<n;gap++){
            for(int i=0;i<n-gap;i++){
                int j=i+gap;
                if(str[i]==str[j] &&  palcache[i+1][j-1])
                    palcache[i][j]=1;
            }
        }
        return getPartitions(0,str.size()-1,str);
    }
};
