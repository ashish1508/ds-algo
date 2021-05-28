class Solution {
public:
    int checkAllZeros(vector<int> &c){
        for(int i=0;i<26;i++){
            if(c[i]!=0) return 0;
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> c(26,0);

        for(int i=0;i<s1.size();i++){
            c[s1[i]-97]++;
        }
        
        int i=0,j=0,ans=0, n=s2.size();
        for(j=0;j<s1.size();j++){
             c[s2[j]-97]--;
        }
        if(checkAllZeros(c)) return true;
        
        while(j<n){
            c[s2[j]-97]--;
            c[s2[i]-97]++;
            if(checkAllZeros(c)) return true;
            j++;
            i++;   
        }
        return false;
    }
};
