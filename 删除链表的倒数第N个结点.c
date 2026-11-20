//LeetCode    19.删除链表的倒数第N个结点

//方法一：哨兵节点加双指针
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode p = {0, head};
    struct ListNode* fast = &p, *cur = &p;
    while (n--)
    {
        fast = fast->next;
    }
    struct ListNode* prev = NULL;
    while (fast)
    {
        fast = fast->next;
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    free(cur);
    return p.next;
}
