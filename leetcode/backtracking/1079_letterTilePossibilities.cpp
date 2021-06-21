class Solution {
public:

    void getNumTilePossibilities(vector<int> &count, int &ans){
          
        for(int i=0;i<26;i++){
            if(count[i]>0){
                count[i]--;
                ans++;
                getNumTilePossibilities(count,ans);
                count[i]++;
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        vector<int> count(26,0);
        for(int i=0;i<tiles.size();i++)
            count[tiles[i]-'A']++;
    
        int ans=0;
        getNumTilePossibilities(count,ans);
        return ans;
    }
};
