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
        unordered_set<char> us;
        for(int i=0;i<s1.size();i++){
            c[s1[i]-97]++;
            us.insert(s1[i]);
        }
        
        int i=0,j=0,ans=0, n=s2.size();
        for(j=0;j<s1.size();j++){
            if(us.find(s2[j])!=us.end()) c[s2[j]-97]--;
        }
        if(checkAllZeros(c)) return true;
        
        while(j<n){
            if(us.find(s2[j])!=us.end()) c[s2[j]-97]--;
            if(us.find(s2[i])!=us.end()) c[s2[i]-97]++;
            if(checkAllZeros(c)) return true;
            j++;
            i++;   
        }
        return false;
    }
};
