// finding last. element less tha or equal to B
int Solution::solve(vector<int> &A, int B) {
    int lo=0,n=A.size(),hi=n-1,mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(A[mid]<=B) lo=mid+1;
        if(A[mid]>B) hi=mid-1;
    }
    return hi+1;
}

// finding first element greater than B
int Solution::solve(vector<int> &A, int B) {
    int lo=0,n=A.size(),hi=n-1,mid;
    while(lo<hi){
        mid=lo+(hi-lo)/2;
        if(A[mid]<=B) lo=mid+1;
        if(A[mid]>B) hi=mid;
    }
    if(A[lo]<=B) return lo+1;
    return lo;
}
