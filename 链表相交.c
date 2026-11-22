//LeetCode    160.链表相交

//方法一：统计长度先走差距步
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* curA = headA, *curB = headB;
    int cntA = 0, cntB = 0;
    while (curA)
    {
        curA = curA->next;
        cntA++;
    }
    while (curB)
    {
        curB = curB->next;
        cntB++;
    }
    curA = headA, curB = headB;
    int gap = cntA - cntB;
    if (gap > 0)
    {
        while (gap--)
        {
            curA = curA->next;
        }
    }
    else
    {
        while (gap++)
        {
            curB = curB->next;
        }
    }
    while (curA != curB)
    {
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}

//方法二：双指针两链表衔尾遍历
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    while (curA != curB)
    {
        curA = curA ? curA->next : headB;
        curB = curB ? curB->next : headA;
    }
    return curA;
}
