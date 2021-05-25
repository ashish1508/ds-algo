int Solution::solve(string A) {
    stack<char> s;
    for(int i=0;i<A.size();i++){
        if(A[i]=='('){
            s.push(A[i]);
        }else{
            if(!s.empty()){
                s.pop();
            }else{
                break;
            }
        }
    }
    if(!s.empty()) return 0;
    if(i==A.size()) return 1;
    return 0;
}
