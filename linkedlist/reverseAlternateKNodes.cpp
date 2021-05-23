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
ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* ret = NULL;
    ListNode* c = A;
    ListNode* p = NULL;
    while(c){
        ListNode* temp = reverse(c,B);
        if(ret == NULL) ret = temp;
        else p->next = temp;
        int i=B+1;
        while(c && i--){
            p = c;
            c = c->next; 
        }
    }
    return ret;
}
