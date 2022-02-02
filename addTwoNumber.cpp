#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;

        ListNode newHead(0);
        ListNode *t = &newHead;

        while (l1 || l2 || carry)
        {
            carry = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;

            t->next = new ListNode(carry % 10);
            t = t->next;

            carry = carry / 10;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return newHead.next;
    }
};