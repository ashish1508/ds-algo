
// approach : take boolean at last
int mod=1003; 
pair<int,int> go(int s, int e, string &st, vector<vector<pair<int,int>>> &cache){
    if(s>e) return {0,0};
    if(s==e && st[s]=='T') return {1,0};
    if(s==e && st[s]=='F') return {0,1};
    if(cache[s][e].first!=-1) return cache[s][e];
    int nt=0,nf=0;
    for(int i=s+1;i<e;i+=2){
        pair<int,int> before = go(s,i-1,st,cache);
        pair<int,int> after = go(i+1,e,st,cache);
        if(st[i]=='&'){
            nt += (before.first * after.first);
            nf += before.first * after.second + before.second * after.first + before.second * after.second;
        }else if(st[i]=='|'){
            nt += before.first * after.first + before.first * after.second + before.second * after.first;
            nf += before.second * after.second;
        }else if(st[i]=='^'){
            nt += before.first * after.second + before.second * after.first;
            nf += before.first * after.first + before.second * after.second;
        }
    }
    //cout<<s<<" "<<e<<" -- "<<nt<<" "<<nf<<endl;
    cache[s][e] = {nt%mod,nf%mod};
    return cache[s][e];
    
}
int Solution::cnttrue(string A) {
    vector<vector<pair<int,int>>> cache;
    cache.resize(A.size(),vector<pair<int,int>>(A.size(),{-1,-1}));
    pair<int,int> p = go(0,A.size()-1,A,cache);
    return p.first;
}
