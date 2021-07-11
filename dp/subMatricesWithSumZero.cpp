

// O(n^3) solution
int subZero(int c1,int c2,vector<vector<int>> &A){
    vector<int> arr;
    for(int i=0;i<A.size();i++){
        int hi = A[i][c2];
        int lo = c1==0 ? 0 : A[i][c1-1];
        arr.push_back(hi-lo);
    }
    unordered_map<int,int> um;
    for(int i=1;i<arr.size();i++)
        arr[i] += arr[i-1];
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0) ans++;
        if(um.find(arr[i])==um.end()){
            um[arr[i]]=1;
            continue;
        }
        ans += um[arr[i]];
        um[arr[i]]++;
    }
    return ans;
}



int Solution::solve(vector<vector<int> > &A) {
    
    if(A.size()==0) return 0;

    int r = A.size();
    int c = A[0].size();
    int ans=0;

    for(int i=0;i<r;i++){
        for(int j=1;j<c;j++){
            A[i][j] += A[i][j-1];
        }
    }
    for(int c1=0;c1<c;c1++){
        for(int c2=c1;c2<c;c2++){
           ans += subZero(c1,c2,A);
        }
    }
    return ans;
}
