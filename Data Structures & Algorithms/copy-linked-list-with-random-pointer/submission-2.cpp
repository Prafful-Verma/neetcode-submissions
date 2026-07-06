/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node* head1 = NULL;
        if (head != NULL) {
            Node* temp = (head);
            while ((temp) != NULL) {
                Node* new_node = NULL;
                new_node = new Node(temp->val);
                new_node->next = temp->next;
                temp->next = new_node;
                temp = temp->next->next;
            }
            temp = (head);
            Node* temp1 = (head);
            while (temp != NULL) {
                if (temp->random != NULL) {
                    temp->next->random = temp->random->next;
                }
                temp = temp->next->next;
            }
            temp = head;
            head1 = new Node(5);
            Node* copy = NULL;
            Node* clone = head1;
            while (temp != NULL) {
                Node* curr = temp->next->next;
                copy = temp->next;
                clone->next = copy;
                clone = copy;
                temp->next = curr;
                temp = curr;
            }
        }
        if (head != NULL)
            return head1->next;
        else
            return head;
    }
};