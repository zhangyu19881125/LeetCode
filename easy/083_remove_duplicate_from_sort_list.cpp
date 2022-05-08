#include "../include/include.h"

ListNode* Solution(ListNode* head)
{
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* curr = head;
    while (curr->next != nullptr)
    {
        if (curr->value == curr->next->value) curr->next = curr->next->next;
        else curr = curr->next;
    }
    return dummy->next;
}

// 递归解法
ListNode* Solution2(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) return head;
    if (head->value == head->next->value)
    {
        head->next = Solution2(head->next->next);
    }
    else
    {
        head->next = Solution(head->next);
    }
    return head;
}
