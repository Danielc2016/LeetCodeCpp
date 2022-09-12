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
    ListNode* swapPairs(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        dummy->next = head;
        ListNode* prev = dummy;
        
        while(curr && curr->next)
        {
            ListNode* secNext = curr->next->next;
            ListNode* sec = curr->next;
            
            prev->next = sec;
            curr->next = secNext;
            sec->next = curr;
            
            prev = curr;
            curr = secNext;
        }
        return dummy->next;
    }
};
