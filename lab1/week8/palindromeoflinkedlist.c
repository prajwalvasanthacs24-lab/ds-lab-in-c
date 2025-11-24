struct ListNode* rev(struct ListNode* head) {
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* nex = NULL;
    while (curr) {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* second = rev(slow->next);
    struct ListNode* p1 = head;
    struct ListNode* p2 = second;
    bool result = true;

    while (p2) {
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    slow->next = rev(second);
    return result;
