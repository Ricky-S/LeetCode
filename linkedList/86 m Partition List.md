# [86. Partition List](https://leetcode.com/problems/partition-list/)

## Description

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.


Example 1:

![image](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)

```
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```

Example 2:

```
Input: head = [2,1], x = 2
Output: [1,2]
```

Constraints:

- The number of nodes in the list is in the range [0, 200].


- -100 <= Node.val <= 100


- -200 <= x <= 200


## Solution
[explanation1](https://leetcode.com/problems/partition-list/discuss/29185/Very-concise-one-pass-solution)

[explanation2](https://leetcode.com/problems/partition-list/solutions/2315494/java-c-detailed-explanation/)

```cpp
```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* greater = new ListNode(0);
        ListNode* lessHead = less;
        ListNode* greaterHead = greater;
        while (head != NULL) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        greater->next = NULL;
        less->next = greaterHead->next;
        return lessHead->next;
    }
};

```