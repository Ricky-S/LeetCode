# [725. Split Linked List in Parts](https://leetcode.com/problems/split-linked-list-in-parts/)



## Description

Given the `head` of a singly linked list and an integer `k`, split the linked list into `k` consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return *an array of the* `k` *parts*.


Example 1:

![img](https://assets.leetcode.com/uploads/2021/06/13/split1-lc.jpg)

```
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]

```

Example 2:

![img](https://assets.leetcode.com/uploads/2021/06/13/split2-lc.jpg)

```
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[2] is null, but its string representation as a ListNode is [].

```

Constraints:

- The number of nodes in the list is in the range `[0, 1000]`.

- `0 <= Node.val <= 1000`

- `1 <= k <= 50`

## Solution

```cpp
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int len = 0;
        ListNode *cur = head;
        while (cur)
        {
            len++;
            cur = cur->next;
        }

        int n = len / k;
        int m = len % k;

        vector<ListNode *> res(k, nullptr);
        cur = head;
        for (int i = 0; i < k && cur; i++)
        {
            res[i] = cur;
            int size = n + (i < m ? 1 : 0);
            for (int j = 0; j < size - 1; j++)
            {
                cur = cur->next;
            }
            ListNode *next = cur->next;
            cur->next = nullptr;
            cur = next;
        }

        return res;
    }
};
```