/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* deleteAndInsertBefore(ListNode* head, ListNode* node, int c){
  
    ListNode* prev=NULL, *curr=head;
    while(curr->val != node->val){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    
 
    if(node->val <= head->val){
        node->next = head;
        return node;
    }
    
    prev = NULL, curr=head;
    while(c-- && curr->val<node->val){
        prev = curr;
        curr = curr->next;
    }
 
    prev->next = node;
    node->next = curr;
    return head;
    
} 
void display(ListNode* A){
    while(A){
        cout<<A->val<<" ";
        A = A->next;
    }
    cout<<endl;
}
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode* curr = A->next;
    ListNode* ret=A;
    int nodes=1;
    while(curr){
        ListNode* temp = curr->next;
        ret = deleteAndInsertBefore(ret,curr,nodes);
        //display(ret);
        nodes++;
        curr = temp;
    }
    return ret;
}
