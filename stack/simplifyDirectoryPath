
// VVIP ---- use append instead of + for string concatenation otherwise TLE

string Solution::simplifyPath(string A) {
    vector<string> vs;
    string s="";
    
    // constructing vector of strings
    for(int i=1;i<A.size();i++){
        if(A[i]=='/'){
            if(s.size())
                vs.push_back(s);
            s="";
            continue;
        }
        s = s+A[i];
    }
    if(s.size()) vs.push_back(s);
    
    // doing stack ops
    stack<string> st;
    stack<string> st2;
    for(int i=0;i<vs.size();i++){
        
        if(vs[i]=="."){
            continue;
        }else if(vs[i]==".."){
            if(!st.empty())
                st.pop();
        }else{
            st.push(vs[i]);
        }
    }
    
    // Reversing the elements of the stack
    while(!st.empty()){
        st2.push(st.top());
        st.pop();
    }
    
    // constructing return string
    string ret="/";
    while(!st2.empty()){
        ret.append(st2.top());
        st2.pop();
        if(!st2.empty()){
            ret.append("/");
        }
    }
    return ret;
    
}
