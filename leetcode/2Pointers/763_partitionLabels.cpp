// first implementation
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> vec(26,0);
        unordered_set<char> us;
        int flag,count=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            vec[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            vec[s[i]-'a']--;
            count++;
            us.insert(s[i]);
            flag=1;
            for(auto is=us.begin();is!=us.end();is++){
                if(vec[(*is)-'a']!=0) flag=0;
            }
            if(flag==1){
                ans.push_back(count);
                count=0;
                us.clear();
            }
        }
        return ans;
    }
};

// range method implementation
//explanation : https://leetcode.com/problems/partition-labels/discuss/899214/2-solutions-(explanation-%2B-picture)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> vec(26,0);
        for(int i=0;i<s.size();i++)
            vec[s[i]-'a']=i;
        vector<int> ans;

        int j=0,maxi=0;
        for(int i=0;i<s.size();i++){
            maxi = max(maxi,vec[s[i]-'a']);
            
            if(maxi==i){
                ans.push_back(i-j+1);
                j = i+1;
            }
        }
        return ans;
    }
};
