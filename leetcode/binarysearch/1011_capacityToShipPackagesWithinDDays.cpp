// Find least ship weight which can can complete shipping within D days : question itself tells binary search :D

class Solution {
public:
    int numberOfDays(vector<int> &w, int ship_weight){
        int days=1,curr_total_weight=0;
        for(int i=0;i<w.size();i++){
          curr_total_weight += w[i];
          if(curr_total_weight>ship_weight){
              days++;
              curr_total_weight = w[i];
          }  
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            maxi = max(maxi,weights[i]);
        }
        int lo=maxi,hi=sum,mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(numberOfDays(weights,mid)>days) lo=mid+1;
            if(numberOfDays(weights,mid)<=days) hi=mid;
        }
        return lo;
    }
};
