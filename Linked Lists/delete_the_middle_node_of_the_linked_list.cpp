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
    ListNode* deleteMiddle(ListNode* head) {
    
        int n = 0;
        ListNode* remp  = head;
        while(remp){
          remp = remp->next;
          n++;
        }    if(n==1) return NULL;
        remp= head;
        int i = 0;
        while(i<(n/2)-1){
            remp=  remp->next;
            i++;
        }
        remp->next = remp->next->next;
        // remp
        // remp->val = remp->next->val;
        // remp->next = remp->next->next ;
        return head;
    }
};
