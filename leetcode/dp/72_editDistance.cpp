
// fun fact : here top down is much faster than bottom up
// can also do in O(1) space
// top down
class Solution {
public:
    vector<vector<int>> cache;
    int editDistance(int w1, int w2, string &word1, string &word2){
        if(w1==-1 && w2==-1) return 0;
        if(w1==-1) return w2+1;
        if(w2==-1) return w1+1;
        if(cache[w1][w2]!=-1) return cache[w1][w2];
        if(word1[w1]==word2[w2])
            return editDistance(w1-1,w2-1,word1,word2);
        int del = 1 + editDistance(w1-1,w2,word1,word2);
        int rep = 1 + editDistance(w1-1,w2-1,word1,word2);
        int ins = 1 + editDistance(w1,w2-1,word1,word2);
        cache[w1][w2] = min({del,rep,ins});
        return cache[w1][w2];
    }
    int minDistance(string word1, string word2) {
        cache.resize(word1.size(),vector<int>(word2.size(),-1));
        return editDistance(word1.size()-1,word2.size()-1,word1,word2);  
    }
};

// bottom up
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> cache;
         cache.resize(word1.size()+1,vector<int>(word2.size()+1,0));
        cache[0][0]=0;
        for(int i=1;i<word1.size()+1;i++){
            cache[i][0] = i;
        }
        for(int i=1;i<word2.size()+1;i++){
            cache[0][i] = i;
        }
        //cout<<"hey"<<endl;
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                cout<<i<<" "<<j<<endl;
                if(word1[i-1]==word2[j-1]){
                    cache[i][j] = cache[i-1][j-1];
                    continue;
                }
                int del = 1+cache[i-1][j];
                int rep = 1+cache[i-1][j-1];
                int ins = 1+cache[i][j-1];
                cache[i][j] = min({del,rep,ins});
            }
        }
        return cache[word1.size()][word2.size()];
    }
};
