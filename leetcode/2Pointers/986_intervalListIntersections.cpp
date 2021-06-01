
// my first implementation O(m*n) m->firstList size n->secondList size

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        for(int i=0;i<firstList.size();i++){
            for(int j=0;j<secondList.size();j++){
                if(secondList[j][1]<firstList[i][0]) continue;
                if(secondList[j][0]>firstList[i][1] ) break;
                vector<int> temp;
                temp.push_back(max(firstList[i][0], secondList[j][0]));
                temp.push_back(min(firstList[i][1], secondList[j][1]));
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

// O(m+n) implementation 
// leetcode solution tab

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<firstList.size() && j<secondList.size()){
            int s = max(firstList[i][0],secondList[j][0]);
            int e = min(firstList[i][1],secondList[j][1]);
            if(s<=e){
                vector<int> t;
                t.push_back(s);
                t.push_back(e);
                ans.push_back(t);
            }
            if(firstList[i][1]<secondList[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};
