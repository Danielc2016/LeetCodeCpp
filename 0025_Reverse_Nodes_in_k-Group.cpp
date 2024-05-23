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
        if(!head || !head->next || k == 1) return head;
        
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode* group_head_prev = dummy_head;
        
        for(int i = 1; head; ++i){
            if(i%k == 0){
                /*
                for 12345, k = 3, 
                it will reverse the first group when head points to 3,
                at that time,
                group_head_prev is 0, head->next is 4
                */
                group_head_prev = reverseOneGroup(group_head_prev, head->next);
                head = group_head_prev->next;
            }else{
                head = head->next;
            }
        }
        
        return dummy_head->next;
    }

    ListNode* reverseOneGroup(ListNode* head_prev, ListNode* tail_next){
        //head_prev: the node before current group's head
        //tail_prev: the node after current group's tail
        /**
         * Reverse a link list between begin and end exclusively
         * an example:
         * a linked list:
         * 0->1->2->3->4->5->6
         * |           |   
         * begin       end
         * after call begin = reverse(begin, end)
         * 
         * 0->3->2->1->4->5->6
         *          |  |
         *      begin end
         * @return the reversed list's 'begin' node, 
         which is the precedence of node end
         */
        ListNode* cur = head_prev->next;
        ListNode* new_head_prev = cur;
        ListNode* prev = head_prev;
        ListNode* next;
        /*
        0->1->2->3->4, begin: 0, end: 4, cur: 1
        1->0
        2->1->0
        3->2->1->0
        prev: the previous node of cur
        next: the next node of cur
        */
        while(cur != tail_next){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        /*
        now:
        prev: 3, cur: 4
        */
        head_prev->next = prev;
        new_head_prev->next = cur;
        
        return new_head_prev;
    };
};
