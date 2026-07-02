class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        stack<ListNode*> st;
        ListNode* curr = head;
        int n = 0;

        while (curr) {
            st.push(curr);
            curr = curr->next;
            n++;
        }

        curr = head;

        for (int i = 0; i < n / 2; i++) {
            ListNode* last = st.top();
            st.pop();

            ListNode* nextNode = curr->next;
            curr->next = last;
            last->next = nextNode;

            curr = nextNode;
        }

        curr->next = nullptr;
    }
};