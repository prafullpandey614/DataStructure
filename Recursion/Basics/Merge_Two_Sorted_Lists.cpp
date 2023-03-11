
class Solution {
public:
    void add(ListNode*list1,ListNode*list2,ListNode*ans){
        if(!list1) {ans->next = list2 ; return  ;}
        if(!list2) {ans->next = list1 ; return ;}
        if(list1->val>list2->val){
            ans->next = new ListNode(list2->val) ;
            ans = ans->next ;
            list2  = list2->next; 
            add(list1,list2,ans);
        }
        else{
            ans->next = new ListNode(list1->val) ;
            ans = ans->next ;
            list1 = list1->next ;
            add(list1,list2,ans);
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*dj = new ListNode(0) ;
        ListNode*ans = dj ;
        add(list1,list2,dj);
        return ans->next;
    }
};
