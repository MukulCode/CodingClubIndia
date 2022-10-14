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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!=NULL) { // until last position
             
            slow = slow->next; // this is incrementing only 1 step at a time
            
            if(fast->next->next!=NULL) { // If we can increment by 2 steps without trying to access null pointer then increment by 2
                fast = fast->next->next; // this is incrementing 2 step at a time
            }
            else { // else increment by 1 only
                fast = fast->next;
            }
        }
        return slow; // when fast is at end of the linked list, slow is at middle
    }
};

/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow;
        ListNode *fast;
        slow = head;
        fast = head;
        while(fast!=NULL && fast->next != NULL) { 
        // while(fast->next != NULL && fast!=NULL) {  //Dont first check the next condition , you always have to check current NULL condition and then check next NULL condition
            
                fast = fast->next->next;    
                slow = slow->next;
        }
        return slow;
    }    
};
*/