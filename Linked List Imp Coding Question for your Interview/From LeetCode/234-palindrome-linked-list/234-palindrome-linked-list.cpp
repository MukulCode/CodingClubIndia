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
    
    // for this function: 
    // (refer 206. Reverse Linked List) 
    // or (https://leetcode.com/problems/reverse-linked-list/)
    ListNode* reverseList(ListNode* head) { 
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = head->next;
        while(nextNode!=NULL) { 
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        curr->next = prev;
        return curr;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* start = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        
        while(slow) {
            if(start->val != slow->val) {
                return false;
            }
            start = start->next;
            slow = slow->next;
        }
        return true;
    }
    
    
//     bool isCheck(ListNode* head1, ListNode* head2) {
        
//         // we can use head2 as well (both are of same length)
//         while(head1) { 
            
//             // equal value in it, move forward
//             if(head1->val == head2->val) { 
                
//                 cout << "head1 : " << head1->val << endl;
//                 cout << "head2 : " << head2->val << endl;
                
//                 head1 = head1->next;
//                 head2 = head2->next;
                
//                 // cout << "head1 : " << head1->val << endl;
//                 cout << "head2 : " << head2->val << endl;
//             }
//             // not equal, so not a Palindrome
//             else if(head1->val != head2->val){ 
//                 return false;
//             }   
//         }
        
//         // The false condition didn't triggered so that means all values are same in head1 list and head2 list so Palindrome
//         return true; 
//     }
};