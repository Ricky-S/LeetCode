# [92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)

## Description

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.


Example 1:

![img](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

```

Example 2:

```
Input: head = [5], left = 1, right = 1
Output: [5]

```

Constraints:


- The number of nodes in the list is `n`.


- `1 <= n <= 500`


- `-500 <= Node.val <= 500`


- `1 <= left <= right <= n`


**Follow up:** Could you do it in one pass?

## Solution

[draw explanation](https://leetcode.com/problems/reverse-linked-list-ii/solutions/30709/talk-is-cheap-show-me-the-code-and-drawing/?envType=daily-question&envId=2023-09-07)

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        for (int i = 0; i < left - 1; i++)
        {
            pre = pre->next;
        }

        ListNode *cur = pre->next;
        ListNode *next = nullptr;
        for (int i = 0; i < right - left; i++)
        {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }

        return dummy->next;
    }
};
```