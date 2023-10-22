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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;
        
        while (head) {
            ListNode* groupStart = head;
            ListNode* groupEnd = getGroupEnd(head, k);
            
            if (!groupEnd) break;
            
            
            ListNode* nextGroupStart = groupEnd->next;
            groupEnd->next = nullptr; 
            
            prevGroupTail->next = reverseList(groupStart);
            groupStart->next = nextGroupStart;
            
            prevGroupTail = groupStart;
            head = nextGroupStart;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
    
private:
    ListNode* getGroupEnd(ListNode* head, int k) {
        while (head && k > 1) {
            head = head->next;
            k--;
        }
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
