ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode* curr=A, *prev=NULL, *head=A, *ret=NULL;
    
    while(curr){
        
        // No next element to compare i.e next element is null
        if(curr->next == NULL ){
            if(ret==NULL){
                ret = curr;
                head = curr;
                curr = curr->next;
                continue;
            }
            head->next = curr;
            head = head->next;
            curr = curr->next;
        }
        
        
        if(curr->next && curr->val != curr->next->val){
            if(ret==NULL){
                ret = curr;
                head = curr;
                curr = curr->next;
                continue;
            }
            head->next = curr;
            head = head->next;
            curr = curr->next;
        }else{
           while(curr && curr->next && curr->val == curr->next->val){
                curr = curr->next;
            } 
            if(curr) curr = curr->next;
        }
        
    }
    head->next = NULL;
    return ret;
 
}
