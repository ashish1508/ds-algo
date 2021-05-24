/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* A){
    ListNode* prev=NULL;
    ListNode* curr = A;
    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
} 

ListNode* merge(ListNode* l1, ListNode* l2, int c,int n){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    
    if(!(c%2) && l1){
        l1->next = merge(l1->next,l2,++c,n);
        return l1;
    }
    
    if(l2){
    l2->next = merge(l1,l2->next,++c,n);
    return l2;
    }
    
}

ListNode* Solution::reorderList(ListNode* A) {

    ListNode* list2 = NULL;
    ListNode* curr = A, *l1 = NULL, *l2 = NULL, *slow=A, *fast=A;
    int c=0;
    int count = length(A);

    curr = A;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    list2 = slow->next;
    slow->next = NULL;
    
    ListNode* revlist2 = reverse(list2);
    ListNode* retList = merge(A,revlist2,0,count);
    return retList;
    
}
