#include <bits/stdc++.h>

using namespace std;

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() < 1)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        vector<int> arr;
        for (int i = 0; i < lists.size(); ++i)
        {
            while (lists[i] != NULL)
            {
                arr.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(arr.begin(), arr.end());
        ListNode *t = new ListNode(0);
        ListNode *dummyHead = t;

        for (int i = 0; i < arr.size(); ++i)
        {
            ListNode *tmp = new ListNode(arr[i]);
            t->next = tmp;
            t = t->next;
        }

        return dummyHead->next;
    }
};