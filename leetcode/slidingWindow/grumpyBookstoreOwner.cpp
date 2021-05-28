class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0,prev=0,next=0,i=0,j=0,curr=0,total=0;
        for(int i=0;i<customers.size();i++)
            total += customers[i]*(!grumpy[i]);
        next = total;
        while(j<minutes){
            curr += customers[j];
            next -= customers[j]*(!grumpy[j]);
            j++;
        }
        ans = prev+curr+next;
        ans = max(ans,total);
        while(j<customers.size()){
            curr += customers[j];
            curr -= customers[i];
            prev += customers[i]*(!grumpy[i]);
            next -= customers[j]*(!grumpy[j]);
            j++;
            i++;
            ans = max(ans,prev+curr+next);
        }
        return ans;
    }
};

// ****** better written code from discuss on leetcode *******
// class Solution {
// public:
//     int maxSatisfied(vector<int>& cus, vector<int>& gpy, int k) 
//     {
//         int without=0,n=cus.size();
//         for(int i=0;i<n;i++)
//             if(gpy[i]==0)
//                 without+=cus[i];
//         for(int i=0;i<k;i++)
//             if(gpy[i])
//                 without+=cus[i];
//         int res=without;
//         for(int i=k,j=0;i<n;i++,j++)
//         {
//             if(gpy[j])
//                 without-=cus[j];
//             if(gpy[i])
//                 without+=cus[i];
//             res=max(res,without);
//         }
//         return res;
//     }
// };
