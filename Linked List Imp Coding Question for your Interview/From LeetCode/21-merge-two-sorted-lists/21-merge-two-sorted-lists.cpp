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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* dummy = new ListNode(-1); //dummy node
        ListNode* tail = dummy;
        
        while(l1!=NULL && l2!=NULL) {
            
            if(l1->val < l2->val) {
                tail -> next = l1;
                tail = l1;
                l1 = l1 -> next;
            }
            else {
                tail -> next = l2;
                tail = l2;
                l2=l2->next;
            }
        }
        
        if(l1==NULL)
            tail -> next = l2;
        else
            tail -> next = l1;
        
        return dummy->next;
    }
};