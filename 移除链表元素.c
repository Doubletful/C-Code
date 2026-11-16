//LeetCode    203.移除链表元素

//方法一：哨兵节点链接非val节点
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode p;
    p.next = NULL;
    struct ListNode* prev = &p;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val != val)
        {
            prev->next = cur;
            prev = prev->next;
        }
        cur = cur->next;
    }
    prev->next = NULL;
    return p.next;
}

//方法二：递归
