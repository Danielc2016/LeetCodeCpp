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

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        while(head)
        {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
    
    ListNode* middleNode(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(!fast)
            {
                break;
            }
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        auto mid = middleNode(head);
        auto R = reverseList(mid), L = head -> next;
        for(int i = 0; L!=R; i++, head = head->next)
        {
            if(i & 1 )
            {
                head->next = L;
                L = L->next;
            }
            else
            {
                head->next = R;
                R = R->next;
            }
        }
    }
};


