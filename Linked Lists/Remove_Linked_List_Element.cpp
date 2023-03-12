/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void rem(ListNode*prev,ListNode*head, int val){
        if(!head) return ;
        if(!head->next){
            if(head->val==val){
                prev->next = NULL;
                return ;
            }
            return ;
        }
        else{
            if(head->val==val){
                prev->next = head->next ;
                head = prev->next ;
            }
            else{
                prev= head ;
                head = head->next;
                
            }
            
            
            rem(prev,head,val);

        }
    }
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head) return NULL;
        
        while(head  && head->val==val){
            head = head->next;
        }
        if(!head) return NULL;
        ListNode*temp  = head ;
        rem(head,head->next,val);
        return temp ;
    }
};
