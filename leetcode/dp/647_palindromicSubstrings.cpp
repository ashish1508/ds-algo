// method-1 
// bruteforce get all substrings..check if there palindrome or not - O(n^3)
// top down (caching palindromes normally)
class Solution {
public:

    vector<vector<int>> cache;
    int go(int s, int e, string &str){ 
        if(s>e) return 0;
        if(s==e) return 1;
        if(cache[s][e]!=-1) return cache[s][e];
         // if(str[s]==str[e] && (s+1==e || cache[s+1][e-1])) will not work because all subproblems might not be solved
        if(str[s]==str[e] && (s+1==e || go(s+1,e-1,str))){
            cache[s][e] = 1;
            return cache[s][e];
        }
        cache[s][e] = 0;
        return cache[s][e];
    }
    int countSubstrings(string s) {
        int n=s.size();
        cache.resize(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<n;i++)
            cache[i][i]=1;
        int ans = s.size(),i,j;
      // not length wise
        for(int i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                ans += go(i,j,s);                
            }
        }
        return ans;
    }
};

// top down ( caching palindromes lengthwise) 
class Solution {
public:

    vector<vector<int>> cache;
    int go(int s, int e, string &str){
        if(cache[s][e]!=-1) return cache[s][e];
        if(s==e){
            cache[s][e]=1;
            return cache[s][e];
        } 
        // if(str[s]==str[e] && (s+1==e || cache[s+1][e-1])) will also work because all subproblems will be definitely solved as we are going lengthwise
        if(str[s]==str[e] && (s+1==e || go(s+1,e-1,str))){
            cache[s][e] = 1;
            return cache[s][e];
        }
        cache[s][e] = 0;
        return cache[s][e];
    }
    int countSubstrings(string s) {
        int n=s.size();
        cache.resize(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<n;i++)
            cache[i][i]=1;
        int ans = s.size(),i,j;
       // length wise    
        for(int gap=1;gap<n;gap++){
            for(i=0;i<n-gap;i++){
                j = i+gap;
                ans += go(i,j,s);            
            }
        }
        return ans;
    }
};

// bottom up
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> cache;
        cache.resize(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<n;i++)
            cache[i][i]=1;
        int ans = s.size(),i,j;
        for(int gap=1;gap<n;gap++){
            for(i=0;i<n-gap;i++){
                j = i+gap;
                if(s[i]==s[j] && (j==i+1 || cache[i+1][j-1])){
                    cache[i][j] = 1;
                    ans++;
                }else{
                    cache[i][j] = 0;
                }
                
            }
        }
        return ans;
    }
};


// method-2
// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/
// top down
class Solution {
public:
    bool isPalindrome(int f, int l, string &s){
        if(f>l) return true;
        if(palcache[f][l]!=-1) return palcache[f][l];
        if(s[f]==s[l] && isPalindrome(f+1,l-1,s)){
            palcache[f][l]=1;
            return true;
        }
        palcache[f][l]=0;
        return false;
    }
    vector<vector<int>> cache;
    vector<vector<int>> palcache;
    int go(int s, int e, string &str){
        if(s>e) return 0;
        if(s==e) return 1;
        if(cache[s][e]!=-1) return cache[s][e];
        if(isPalindrome(s,e,str)){
            cache[s][e] = 1+go(s+1,e,str)+go(s,e-1,str)-go(s+1,e-1,str);
            return cache[s][e];
        }
        cache[s][e] = go(s+1,e,str)+go(s,e-1,str)-go(s+1,e-1,str);
        return cache[s][e];
    }
    int countSubstrings(string s) {
        cache.resize(s.size(),vector<int>(s.size(),-1));
        palcache.resize(s.size(),vector<int>(s.size(),-1));
        
        return go(0,s.size()-1,s);
    }
};

// we can implememt bottom up similarly
