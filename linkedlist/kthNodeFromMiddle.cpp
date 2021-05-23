/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    int l=0;
    ListNode* h = A;
    while(h!=NULL){
        h = h->next;
        l++;
    }
    int val = l/2 + 1;
    ListNode* curr = A;
    int ele = val-B-1;

    while(ele>0 && curr){
        curr = curr->next;
        ele--;
    }
    if(ele<0 || curr==NULL) return -1;
    return curr->val;
}
