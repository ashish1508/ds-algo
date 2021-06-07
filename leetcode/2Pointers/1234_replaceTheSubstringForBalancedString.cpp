// my first implementation
class Solution {
public:
    int index(char c){
        if(c=='Q') return 0;
        if(c=='W') return 1;
        if(c=='E') return 2;
        return 3;
        
    }
    int checkFour(vector<int> &vec, vector<int> &cmax, int n){
        for(int i=0;i<4;i++){
            if(vec[i]>(n/4)){
                if( cmax[i] < vec[i]- n/4) return 0;
            }
        }
        return 1;
    }
    int balancedString(string s) {
        int n = s.size(), ans=INT_MAX,c=0;
        if(n%4) return 0;
        vector<int>vec(4,0);
        vector<int>cmax(4,0);
        for(int i=0;i<n;i++){
            vec[index(s[i])]++;
        }
        for(int i=0;i<4;i++){
            if(vec[i]==n/4) c++;
        }
        if(c==4) return 0;
        int i=0,j=0;
        while(j<n){
            if(vec[index(s[j])]>(n/4)) cmax[index(s[j])]++;
            while(checkFour(vec,cmax,n) && i<=j){
                //cout<<i<<" "<<j<<endl;
                ans = min(ans,j-i+1);
                if(vec[index(s[i])]>(n/4)) cmax[index(s[i])]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};

// better implementation inspired from discuss
class Solution {
public:
    int index(char c){
        if(c=='Q') return 0;
        if(c=='W') return 1;
        if(c=='E') return 2;
        return 3;
        
    }
    int checkFour(vector<int> &vec, int n){
        for(int i=0;i<4;i++){
            if(vec[i]>(n/4)){
                return 0;
            }
        }
        return 1;
    }
    int balancedString(string s) {
        int n = s.size(), ans=INT_MAX,c=0;
        vector<int>vec(4,0);
        for(int i=0;i<n;i++){
            vec[index(s[i])]++;
        }
        if(checkFour(vec,n)) return 0;
        int i=0,j=0;
        while(j<n){
            vec[index(s[j])]--;
            while(checkFour(vec,n) && i<=j){
                ans = min(ans,j-i+1);
                vec[index(s[i])]++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
