/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL || headB == NULL) return NULL;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        // If a & b have different lengths, then we will stop the loop after second iteration
        while(a!=b) {
            
            // for the end of first iteration , we just reset the pointer to the head of another linkedlist
            if(a==NULL) a = headB;
            else a = a->next;
            
            if(b==NULL) b = headA;
            else b = b->next;
        }
        return a;
    }
};