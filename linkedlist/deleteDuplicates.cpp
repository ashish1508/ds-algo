/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A->next == NULL || A==NULL) return A;
    ListNode* ret = A , *l=A;
    ListNode* curr = A->next, *prev=A;
    while(curr){
        if(curr->val != prev->val){
            l->next = curr;
            l = curr;
        }
        prev = curr;
        curr = curr->next;
    }
    l->next = NULL;
    return ret;
}
