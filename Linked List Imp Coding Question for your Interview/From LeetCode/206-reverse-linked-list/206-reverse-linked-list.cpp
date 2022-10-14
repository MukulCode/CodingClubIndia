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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = head->next;
        
        while(nextNode!=NULL) { 
            
            curr->next = prev;
            
            prev = curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        curr->next = prev; // Loop is stopped just before changing the next arrow of last position. That's why we are performing it again for one more time
        
        return curr;
    }
};

/*
Recursion :
class Solution {
public:
    
    ListNode* reverse(ListNode* head) {
        
        if(head->next==NULL) { // Last Node
            return head;
        }
        
        ListNode* reverseHead = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return reverseHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
        return reverse(head);
    }
};
*/