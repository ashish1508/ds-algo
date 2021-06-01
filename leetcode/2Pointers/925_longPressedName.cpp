// first working implementation of mine ::: not good

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=1,j=1,c1=1,c2=1, n=name.size(), t=typed.size();
        if(name[0]!=typed[0] || typed.size()<name.size()) return false;
        while(i<n && j<t){
            while(i<n && name[i]==name[i-1]){
                i++;c1++;
            }
            while(j<t && typed[j]==typed[j-1]){
                j++;c2++;
            }
            
            if(c2<c1 || name[i-1]!=typed[j-1]) return false;
            c1=1;c2=1;i++;j++;
        }
        
        while(j<t && typed[j]==typed[j-1]){
            c2++;j++;
        }
        if(c2<c1 || name[i-1]!=typed[j-1] || j<t ||i<n) return false;
        return true;
        
    }
};

// nice implementation from discuss

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0,c1=0,c2=0, n=name.size(), t=typed.size();

        while(i<n){
            if(j>=t) return false;
            if(name[i]!=typed[j]) return false;
            
            c1=0;c2=0; 
            while(i<n-1 && name[i]==name[i+1]){
                i++;c1++;
            }
            while(j<t-1 && typed[j]==typed[j+1]){
                j++;c2++;
            }
            if(c2<c1) return false;
            i++;j++;
        }
        if(j<t) return false;
        return true;
        
    }
};

// better implementation from discuss

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(i<name.size() || j<typed.size()){
            if(i<name.size() && name[i]==typed[j]){
                i++;j++;
            }else if(i>0 && j<typed.size() && typed[j]==name[i-1]){
                j++;
            }else{
                return false;
            }
        }

       return true;
        
    }
};
