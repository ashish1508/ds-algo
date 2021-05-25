int Solution::trap(const vector<int> &A) {
    if(A.size()<3) return 0;
    int i=0,j=A.size()-1;
    int ans=0,lmax=A[i],rmax=A[j];
    
    while(i<=j){
        lmax = max(lmax,A[i]);
        rmax = max(rmax,A[j]);
        if(lmax<rmax){
            ans += lmax-A[i];
            i++;
        }else{
            ans += rmax-A[j];
            j--;
        }
    }
    return ans;
}
