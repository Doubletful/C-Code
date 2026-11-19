//LeetCode    206.反转链表

//方法一：递归
struct ListNode* reverseList(struct ListNode* head) {
    if (!head || head->next == NULL)
        return head;
    struct ListNode* newhead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

//方法二：双指针
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head)
    {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next; 
    }
    return prev;
}
