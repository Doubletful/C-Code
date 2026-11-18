//LeetCode    707.设计链表

//方法一：单链表使用独立函数实现
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

//方法二：单链表使用存储大小加函数回调实现
typedef struct MyLinkedList {
   int val;
   int size;
   struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* BuyNode(int val)
{
    MyLinkedList* node = malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = NULL;
    return node;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = BuyNode(-1);
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index >= obj->size)
        return -1;
    struct MyLinkedList* cur = obj->next;
    while (index--)
    {
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size)
        return;
    MyLinkedList* prev = obj;
    while (index--)
    {
        prev = prev->next;
    }
    MyLinkedList* node = BuyNode(val);
    node->next = prev->next;
    prev->next = node;
    obj->size++;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index >= obj->size)
        return;
    MyLinkedList* prev = obj;
    while (index--)
    {
        prev = prev->next;
    }
    MyLinkedList* del = prev->next;
    prev->next = del->next;
    free(del);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* del = obj;
    while (del)
    {
        MyLinkedList* next = del->next;
        free(del);
        del = next;
    }
}
