//LeetCode    19.删除链表的倒数第N个结点

//方法一：哨兵节点加递归
int changeTarget(struct ListNode* head, int n)
{
    if (head->next == NULL)
        return 1;
    int num = changeTarget(head->next, n);
    if (num == n)
    {
        struct ListNode* del = head->next;
        head->next = head->next->next;
        free(del);
    }
    return num + 1;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode p = {0, head};
    changeTarget(&p, n);
    return p.next;
}

//方法二：哨兵节点加双指针
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
