class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        if (!head || head->next == head)
            return {head, nullptr};

        Node* slow = head;
        Node* fast = head;

        // Find midpoint using slow & fast
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* head1 = head;
        Node* head2 = slow->next;

        // For odd nodes, move fast to last node
        if (fast->next->next == head)
            fast = fast->next;

        // Make the two halves circular
        fast->next = head2;
        slow->next = head1;

        return {head1, head2};
    }
};
