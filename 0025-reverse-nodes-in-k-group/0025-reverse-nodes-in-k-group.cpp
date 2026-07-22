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
        ListNode dummy;
        dummy.next = head;
        ListNode* groupPrev = &dummy;
        while(true)
        {
            ListNode* kth = groupPrev;
            for(int i=0; i<k && kth != nullptr; i++)
            {
                kth = kth->next;
            }
            if(kth == nullptr)
            {
                break;
            }
            ListNode* groupNext = kth->next;
            ListNode* cur = groupPrev->next;
            ListNode* prev = groupNext;

            while(cur != groupNext)
            {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy.next;
    }
};