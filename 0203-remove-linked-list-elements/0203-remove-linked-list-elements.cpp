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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* del;

        if(head == NULL)
        {
            return head;
        }
        while(temp != NULL)
        {
            while(head != NULL && head->val == val)
            {
                del = head;
                head = head->next;
                delete del;
                temp = head;
            }
            if(temp == NULL)
                 return head;
            if(temp->val == val)
            {
                del = temp;
                prev->next = temp->next;
                temp = temp->next;
                delete del;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        if(temp == NULL || temp->val == val)
        {
            del = temp;
            delete del;
            prev->next = NULL;
        }
        return head;
    }
};