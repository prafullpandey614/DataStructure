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
    ListNode* removeNodes(ListNode* head) {
        if(!head) return NULL ;
        vector<int>arr,ans;
        while(head){
            arr.push_back(head->val);
            head = head->next ;
        }
        stack<int>st;
        for(int i = 0; i<arr.size();++i){
            while(st.size()){
               if(st.size() && st.top()<arr[i]){
                st.pop();
               } 
                else break;
            }
            
            st.push(arr[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        ListNode*temp = new ListNode(1);
        ListNode*p = temp;
        for(auto x:ans){
            ListNode*j = new ListNode(x);
            temp->next = j;
            temp = temp->next ;
        }
        return p->next ;
    }
};
