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
//Priority Queue
class Solution {
public:
    struct compare
    {
        bool operator() (ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* res = new ListNode(0);
        ListNode* last = res;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i]!= NULL)
                pq.push(lists[i]);
        }
        while(!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            last->next = f;
            last = last->next;
            if(f->next)
                pq.push(f->next);
        }
        return res->next;
    }
};

