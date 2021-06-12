int Solution::search(const vector<int> &A, int B) {
    int lo=0,n=A.size(),hi=n-1,mid;
 
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(A[mid]==B) return mid;
        if(A[mid]>A[hi] && B<=A[hi] || A[mid]>A[hi] && B>A[mid] || A[mid]<A[hi] && B>A[mid]) lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}
