/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node* cur = head;
        if(head == nullptr)
        {
            return head;
        }
        while(cur != nullptr)
        {
            if(cur->child != nullptr)
            {
                if(cur->next != nullptr)
                {
                    st.push(cur->next);
                }
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }
            else if(cur->next == nullptr && !st.empty())
            {
                cur->next = st.top();
                st.pop();
                cur->next->prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};