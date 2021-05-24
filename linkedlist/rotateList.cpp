/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode* A){
    ListNode* curr = A;
    int count=0;
    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
} 
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int l = length(A);
    if(B%l == 0) return A;
    int c = l-(B%l)+1;
    ListNode* ret = NULL;
    int count=1;
    ListNode* curr=A, *prev=NULL;
    
    while(curr){
        if(count==c){
            prev->next = NULL;
            ret = curr;
        }
        count++;
        prev = curr;
        curr = curr->next;
    }
    prev->next = A;
    return ret;
    
}
