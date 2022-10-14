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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* p1;
        ListNode* p2;
        ListNode* toDel;
        
        p1 = head;
        p2 = head;
        
        while(n--) {
            p2 = p2->next; // only move p2 pointer
        }
        
        if (!p2) { // This condition will be True when they asked to delete head
            
            toDel = head;
            head = head->next;
            delete toDel;
            
            return head;
        }
            
        while (p2->next) {
            p1 = p1->next; // simultaneously move both the pointers
            p2 = p2->next;
        }
        
        toDel = p1->next;
        p1->next = p1->next->next;
        delete toDel;
        
        return head;
    }
    
    /*
    // Brute Force:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* toDel;
        
        if(head->next==NULL && n==1) 
            return {};
        
        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL) {
            size++;
            temp = temp->next;
        }
        
        if(size == n) { // This condition will be True when they asked to delete head
            toDel = head;
            head=head->next;
            
            delete toDel;
            return head;
        }
        
        int loopIterations = size - n - 1; // we are subtracting '1' bcoz we want to go to previous position to the element we want to delete
        
        temp=head;
        while(loopIterations--) {
            temp = temp->next;
        }
        
        toDel = temp->next;
        temp->next = temp->next->next;
        delete toDel;
        
        return head;
    }
    
    */
};