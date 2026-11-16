//LeetCode    203.移除链表元素

//方法一：递归
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (!head)
        return head;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}

//方法二：哨兵节点链接非val节点
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode p;
    p.next = head;
    struct ListNode* cur = &p;
    while (cur->next)
    {
        struct ListNode* nxt = cur->next;
        if (nxt->val == val)
        {
            cur->next = nxt->next;
            free(nxt);
        }
        else
            cur = cur->next;
    }
    return p.next;
}
