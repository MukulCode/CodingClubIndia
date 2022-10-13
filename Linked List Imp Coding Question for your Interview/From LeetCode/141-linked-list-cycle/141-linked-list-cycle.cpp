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
    bool hasCycle(ListNode *head) {
        
        // if head is NULL or there is single node in List then return false;
        if(head == NULL || head->next == NULL) { 
            return false;
        }
        
        // Placed slow and fast at the start of the list
        ListNode* slow = head;
        ListNode* fast = head;
        
        // till fast and fast-> next not reaches NULL
        while(fast!=NULL && fast->next!=NULL) {
            
            // we will increment fast by 2 step and slow by 1 step
            slow = slow->next;
            fast = fast->next->next;
            
            // compulsory
            // first iterate slow and fast pointer and 
            // then check for if slow==fast
            // dont do vice versa
            
            // At the point if fast and slow are at same address
 			// this means linked list has a cycle in it.
            if(slow == fast) {
                return true;
            }
        }
        
        // if traversal in loop reaches to NULL this means that true condition never satisfied so no cycle.
        return false;
    }
};