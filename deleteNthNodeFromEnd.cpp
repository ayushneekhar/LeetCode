#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (n-- > 0)
            fast->next;

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

int main()
{
}