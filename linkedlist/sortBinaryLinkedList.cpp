/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    int o=0,z=0;
    ListNode* curr = A;
    while(curr){
        if(curr->val == 0) z++;
        else o++;
        curr = curr->next;
    }
    curr = A;
    while(curr){
        if(z>0){
            curr->val = 0;
            z--;
        }else{
            curr->val=1;
        }
        curr = curr->next;
    }
    return A;
}
