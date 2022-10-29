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
        
        // If only one node present then by given condition 
        // Middle node = Head node
        if(head->next == NULL) {
            delete head; // so delete head
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next->next; // we want to traverse upto the back of the node we want to delete
        // so that we can delete the node as well as link the remaining nodes of linked list
        ListNode* toDel;
        
        while(fast && fast->next) {
            slow = slow->next; // move forward by 1 node
            fast = fast->next->next;    // move forward by 2 node
        }
        
        toDel = slow->next;
        slow->next = slow->next->next; // link the remaining nodes of linked list
        
        delete toDel; // delete, free up the space
        return head; 
    }
};