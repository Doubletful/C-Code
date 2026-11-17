//LeetCode    707.设计链表

//方法一：单链表
typedef struct MyLinkedList{
    int val;
    struct MyLinkedList* next;
} MyLinkedList;

MyLinkedList* ByListNode(int val)
{
    MyLinkedList* node = malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = NULL;
    return node;
}

MyLinkedList* myLinkedListCreate() {
    return ByListNode(-1);
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* cur = obj->next;
    for (int i = 0; i < index; i++)
    {
        if (cur == NULL)
            return -1;
        cur = cur->next;
    }
    return cur ? cur->val : -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* node = ByListNode(val);
    node->next = obj->next;
    obj->next = node; 
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* node = ByListNode(val);
    MyLinkedList* cur = obj;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = node;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* prev = obj;
    for (int i = 0; i < index; i++)
    {
        if (prev->next == NULL)
            return;
        prev = prev->next;
    }
    MyLinkedList* node = ByListNode(val);
    node->next = prev->next;
    prev->next = node;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* prev = obj;
    for (int i = 0; i < index; i++)
    {
        if (prev->next == NULL)
            return;
        prev = prev->next;
    }
    MyLinkedList* del = prev->next;
    if (del)
        prev->next = del->next;
    free(del);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* cur = obj;
    while (cur)
    {
        MyLinkedList* next = cur->next;
        free(cur);
        cur = next;
    }
}
