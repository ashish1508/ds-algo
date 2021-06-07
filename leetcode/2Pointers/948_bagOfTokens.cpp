class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0) return 0;
        sort(tokens.begin(),tokens.end());
        if(power<tokens[0]) return 0;
        power -= tokens[0];
        int max_score=1,curr_score=1;
        int i=1,j=tokens.size()-1;
        while(i<=j){
            if(power>=tokens[i]){
                power -= tokens[i];
                curr_score++;
                i++;
            }else{
                power += tokens[j];
                curr_score--;
                j--;
            }
            max_score = max(max_score,curr_score);
        }
        return max_score;
    }
};
