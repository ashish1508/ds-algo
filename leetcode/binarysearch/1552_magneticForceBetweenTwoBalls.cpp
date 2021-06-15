class Solution {
public:
    int check(vector<int> &pos,int diff, int m){
        int cp=pos[0];
        m--;
        for(int i=1;i<pos.size();i++){
            if(pos[i]-cp>=diff && m){
                m--;
                cp=pos[i];
            }
        }
        return m==0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        // min force and max force
         int lo=1,hi=A[position.size()]-A[0],mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(check(position,mid,m)) lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};
