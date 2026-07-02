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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while(curr){
            size++;
            curr = curr->next;
        }
        int node = size-n;
        if (node == 0) {
            ListNode* temp = head->next;
            head->next = nullptr;
            return temp;
        }
        int currIdx = 0;
        curr = head;
        ListNode* prev = nullptr;
        while(curr) {
            if (currIdx == node){
                prev->next = curr->next;
                return head;
            }
            prev = curr;
            curr = curr->next;
            currIdx++;
        }
        return head;
    }
};
