/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Floyd Algorithm
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head;
        ListNode *entry = head;
        
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                while(slow != entry)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
            if(!fast)
                return NULL;
        }
        return NULL;
    }
};
