class Solution {
public:
    Node* clone_util(Node* head, map<Node*, Node*>& mp) {
        if (!head) return nullptr;

        // Clone the current node if not already cloned
        if (mp.find(head) != mp.end())
            return mp[head];

        Node* copy = new Node(head->data);
        mp[head] = copy;

        // Recursively clone next and random
        copy->next = clone_util(head->next, mp);
        copy->random = clone_util(head->random, mp);

        return copy;
    }

    Node* cloneLinkedList(Node* head) {
        if (!head) return nullptr;
        map<Node*, Node*> mp;
        return clone_util(head, mp);
    }
};
