bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return false;

    struct ListNode* ptr = head;
    struct ListNode* prev = head;

    while (ptr != NULL && ptr->next != NULL) {
        ptr = ptr->next->next;
        prev = prev->next;

        if (ptr == prev) {
            return true;
        }
    }

    return false;
}
