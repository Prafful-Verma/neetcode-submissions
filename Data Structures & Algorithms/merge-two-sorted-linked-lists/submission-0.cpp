class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* root = nullptr;
        ListNode* curr = nullptr;

        if (list1->val <= list2->val) {
            root = list1;
            list1 = list1->next;
        } else {
            root = list2;
            list2 = list2->next;
        }

        curr = root;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        while (list1 != nullptr) {
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            curr->next = list2;
            curr = curr->next;
            list2 = list2->next;
        }

        return root;
    }
};