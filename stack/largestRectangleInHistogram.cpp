
int Solution::largestRectangleArea(vector<int> &A) {
    vector<int> left;
    stack<pair<int,int> > st;
    left.push_back(-1);
    st.push({A[0],0});
    for(int i=1;i<A.size();i++){
        while(!st.empty() && st.top().first>=A[i]){
            st.pop();
        }
        if(!st.empty()){
            left.push_back(st.top().second);
        }else{
            left.push_back(-1);
        }
        st.push({A[i],i});
    }
    vector<int> right(A.size());
    stack<pair<int,int> > str;
    right[A.size()-1]=-1;
    str.push({A[A.size()-1], A.size()-1});
    
    for(int i=A.size()-2;i>=0;i--){
        while(!str.empty() && str.top().first>=A[i]){
            str.pop();
        }
        if(!str.empty()){
            right[i] = str.top().second;
        }else{
            right[i] = -1;
        }
        str.push({A[i],i});
    }
    

    int ans = INT_MIN;
    int val;
    for(int i=0;i<A.size();i++){
        int l,r;
        l = left[i]==-1 ? 0 : left[i]+1;
        r = right[i]==-1 ? A.size()-1 : right[i]-1;
        if(l==r){
            ans = max(ans,A[i]);
            continue;
        }
        val = (r-l+1)*A[i];
        ans = max(ans,val);

    }
    return ans;
    
}
