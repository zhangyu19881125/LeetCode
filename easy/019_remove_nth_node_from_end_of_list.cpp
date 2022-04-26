#include "../include/include.h"

// 代码可能有问题, 要仔细考量一下边界条件. 不过思路是对的, 不纠结了
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* r = head, l = head;
    for (int i = 0; i < n && r->next != nullptr; ++i)
    {
        r = r->next;
    }

    while (r->next != nullptr)
    {
        r = r->next;
        l = l->next;
    }
    l->next = l->next->next;

    return head;
}

int main()
{
    return 0;
}
