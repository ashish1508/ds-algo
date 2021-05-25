int Solution::braces(string A) {
    int i;
    stack<char> s;
    for(i=0;i<A.size();i++){
        if(A[i]=='(') s.push(A[i]);
        else if(A[i]=='+'||A[i]=='-'||A[i]=='*'||A[i]=='/') s.push(A[i]);
        else if(A[i]==')'){
            if(!s.empty()){
                if(s.top()=='(') break;
                else{
                    while(!s.empty() && s.top()!='('){
                        s.pop();
                    }
                    s.pop();
                }
            }
        }
    }
    if(i==A.size()) return 0;
    return 1;
}
