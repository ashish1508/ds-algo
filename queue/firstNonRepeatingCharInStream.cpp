string Solution::solve(string A) {
    vector<int> count(26,0);
    queue<char> q;
    string ret;
    for(int i=0;i<A.size();i++){
        if(count[A[i]-97]==0){
            q.push(A[i]);
            count[A[i]-97]=1;
        }
    }
    
    for(int i=0;i<A.size();i++){
        if(count[A[i]-97]>=0){
            count[A[i]-97]--;
        }
        
        if(count[A[i]-97]==0){
            ret += q.front();
            continue;
        }
        
        while(!q.empty() && count[q.front()-97]==-1){
                q.pop();
        }
            
        if(!q.empty() && count[q.front()-97]==0){
            ret += q.front();
        }else{
            ret += '#';
        }
        
    }
    return ret;
    
}
