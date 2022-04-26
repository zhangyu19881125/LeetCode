#include "../include/include.h"

ListNode* MergeTwoSortList(ListNode* l, ListNode* r)
{
    // 链表题都需要一个dummy 节点
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (l && r)
    {
        if (l->value < r->value)
        {
            cur->next = l;
            l = l->next;
        }
        else
        {
            ...;
        }
        cur = cur->next;
    }
    cur->next = l ? l : r;
    return dummy->next;
}
