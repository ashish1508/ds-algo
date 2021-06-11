
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo=0,hi=letters.size()-1,mid;
        if(target<letters[0] || target>=letters[letters.size()-1])  return letters[0];
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(letters[mid]<=target) lo=mid+1;
            else hi=mid;
        }
        return letters[lo];
    }
};


