/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* A){
    ListNode *prev=NULL, *curr=A;
    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
int length(ListNode* A){
    int c=0;
    while(A){
        c++;
        A=A->next;
    }
    return c;
}
int checkEqual(ListNode* l1, ListNode* l2){
   
    while(l2){
        if(l1->val != l2->val) return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return 1;
}
int Solution::lPalin(ListNode* A) {
    
    ListNode* prev=NULL, *curr=A, *list2;
    
    int l = length(A);
    int n = l/2;
    while(n--){
        prev = curr;
        curr = curr->next;
    }
    if(prev)
        prev->next = NULL;
    list2 = curr;
    if(l%2)
        list2 = curr->next;
    
    ListNode* revlist2 = reverse(list2);
    return checkEqual(A, revlist2);
    
}
