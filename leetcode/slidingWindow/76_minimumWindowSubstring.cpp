// first implementation
class Solution {
public:
    
    int checkAllZeros(vector<int> &v){
        for(int i=0;i<v.size();i++){
            if(v[i]>0) return 0;
        }
        return 1;
    }
    
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        vector<int> v(52,0);
        vector<int> vt(52,0);
        for(int i=0;i<t.size();i++){
            if(t[i]>='A' && t[i]<='Z'){
                v[t[i]-'A']++;
                vt[t[i]-'A']=1;
            }
            if(t[i]>='a' && t[i]<='z'){
                v[t[i]-'a'+26]++;
                vt[t[i]-'a'+26]=1;
            }
        }
        int i=0,j=0;
        string ret="";
        while(j<s.size()){
            if(s[j]>='A' && s[j]<='Z' && vt[s[j]-'A']) v[s[j]-'A']--;
            if(s[j]>='a' && s[j]<='z' && vt[s[j]-'a'+26]) v[s[j]-'a'+26]--;
            //cout<<i<<" "<<j<<endl;
            while(checkAllZeros(v) && i<=j){
                //cout<<i<<" ------ "<<j<<endl;
                if(ret=="" || j-i+1 < ret.size()){
                   // cout<<i<<" ** "<<j<<endl;
                    ret = s.substr(i,j-i+1);
                    //cout<<ret<<endl;
                    
                }
                if(s[i]>='A' && s[i]<='Z' && vt[s[i]-'A']) v[s[i]-'A']++;
                if(s[i]>='a' && s[i]<='z' && vt[s[i]-'a'+26]) v[s[i]-'a'+26]++;
                i++;
                //cout<<i<<" "<<j<<endl;
                
            }
            j++;
        }
        return ret;
    }
};

