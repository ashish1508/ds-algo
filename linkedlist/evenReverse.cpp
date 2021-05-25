/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* A){
    ListNode* curr=A, *prev=NULL, *temp;
    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
} 
void display(ListNode* A){
    while(A){
        cout<<A->val<<" ";
        A = A->next;
    }
    cout<<endl;
}

ListNode* Solution::solve(ListNode* A) {
    ListNode* l1=NULL, *l2=NULL, *list1=NULL, *list2=NULL;
    int count=1,total=0;
    ListNode* curr = A;
    while(curr){
        if(count%2){
            if(list1==NULL){
                list1=curr;
            }else{
                l1->next = curr;
            }
            l1 = curr;
        }else{
            if(list2==NULL){
                list2=curr;
            }else{
                l2->next = curr;
            }
            l2 = curr;
        }
        count++;
        total++;
        curr = curr->next;
    }
    l1->next=NULL;
    l2->next = NULL;
    ListNode* revList2 = reverse(list2);
    ListNode* retList = new ListNode(-1);
    ListNode* rlist=retList;
    curr = A;
    count = 1;
    //cout<<total<<endl;
    // display(list1);
    // display(revList2);
    
    while(count<=total){
        //cout<<count<<endl;
        if(count%2){
            rlist->next = list1;
            list1 = list1->next;
        }else{
            rlist->next = revList2;
            revList2 = revList2->next;
        }
        rlist = rlist->next;
        count++;
    }
    
    return retList->next;
    
}
