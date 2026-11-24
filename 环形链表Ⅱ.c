//LeetCode    142.环形链表Ⅱ

//方法一：快慢指针加数学证明
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            struct ListNode* node = head;
            while (fast != node)
            {
                fast = fast->next;
                node = node->next;
            }
            return node;
        }
    }
    return NULL;
}
