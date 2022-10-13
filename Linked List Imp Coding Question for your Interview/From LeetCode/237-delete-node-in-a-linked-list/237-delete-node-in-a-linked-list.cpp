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
    void deleteNode(ListNode* node) {
        
        // To delete one node from linked list we should actually present on previous node of the node we want to delete
        // But here they had given us the node they want to delete, not the previous node
        
        swap(node->val, node->next->val); // so we swapped the value stored in that node and the next node
        
        ListNode* toDelete = node->next;
        
        node->next = node->next->next; 
        // node->next = toDelete->next; //We can also write this as well instead of above line
        
        delete toDelete;
    }
};