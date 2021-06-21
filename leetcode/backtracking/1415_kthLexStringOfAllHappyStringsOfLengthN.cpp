class Solution {
public:
    void getKHappyString(int &n, int &k, string s, string &ans){
        if(n==0){
            k--;
            if(k==0)
                ans=s;
            return;
        }
        for(int i=0;i<3;i++){
            if(s.size()>0 && 'a'+i == s[s.size()-1]) continue;
            s.append(1,'a'+i);
            n--;
            getKHappyString(n,k,s,ans);
            n++;
            s.pop_back();
            
        }
    }
    string getHappyString(int n, int k) {
        string s="";
        string ans="";
        getKHappyString(n,k,s,ans);
        return ans;
    }
};
