int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int lo=0,n=A.size(),hi=n-1,mid;
    while(lo<hi){
        mid=lo+(hi-lo)/2;
        if(A[mid]<B) lo=mid+1;
        if(A[mid]>=B) hi=mid;
    }
    // if B  is greater than highest value
    if(A[lo]<B) return lo+1;
    
    return lo;
}
