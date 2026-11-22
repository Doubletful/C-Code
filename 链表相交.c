//LeetCode    160.链表相交

//方法一：统计长度先走差距步


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
