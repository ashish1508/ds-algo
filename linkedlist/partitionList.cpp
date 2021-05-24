/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* l1 = NULL, *l2 = NULL, *list1=NULL, *list2=NULL;
    ListNode* curr = A;
    while(curr){
        if(curr->val < B){
            if(l1==NULL){
                list1=curr;
            }else{
                l1->next = curr;
            }
            l1 = curr;
        }else{
            if(l2==NULL){
                list2=curr;
            }else{
                l2->next = curr;
            }
            l2 = curr;
        }
        curr = curr->next;
    }
    
    if(list1==NULL) return list2;
    
    l2->next=NULL;
    l1->next = list2;
    
    return list1;
}
