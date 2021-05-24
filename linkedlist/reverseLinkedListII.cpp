/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverse(ListNode* head, int val){
    ListNode* prev = head;
    ListNode* curr = prev->next;
    while(curr && --val){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head->next = curr;
    return prev;
} 

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* curr = A;
    ListNode* prev = NULL;
    int count=1;
    while(curr && count<B){
        prev = curr;
        curr = curr->next;
        count++;
    }
    ListNode* ret = reverse(curr,C-B+1);
    if(B==1) return ret;
    else
    prev->next = ret;
    return A;
}
