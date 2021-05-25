int Solution::trap(const vector<int> &A) {
    if(A.size()<3) return 0;
    int i=0,j=A.size()-1;
    int ans=0,lmax=A[i],rmax=A[j];
    while(i<=j){
        if(lmax<rmax){
            ans += lmax-A[i];
            lmax = max(lmax,A[i+1]);
            i++;
        }else{
            ans += rmax-A[j];
            rmax = max(rmax,A[j-1]);
            j--;
        }
    }
    return ans;
}
