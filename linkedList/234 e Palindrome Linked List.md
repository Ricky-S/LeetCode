# 234. Palindrome Linked List

Given the `head` of a singly linked list, return `true` if it is a palindrome.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

```
Input: head = [1,2,2,1]
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

```
Input: head = [1,2]
Output: false
```

constraints:

- The number of nodes in the list is in the range [1, 10^5].
- 0 <= Node.val <= 9

**Follow up:** Could you do it in O(n) time and O(1) space?

**Idea:**

1. find the middle node of the linked list.

2. reverse the second half of the linked list.
3. compare the first half and the second half of the linked list.
4. return the result.
5. $O(n)$

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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast(head);
        ListNode* slow(head);
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev(nullptr);
        ListNode* nextp(nullptr);
        while (slow) {
            nextp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextp;
        }
        while (prev) {
            if (head->val != prev->val) {
                return false;
            }
            // cout << prev->val << endl;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
```

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        fast = head
        slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        prev = None
        nextp = None
        while slow:
            nextp = slow.next
            slow.next = prev
            prev = slow
            slow = nextp
        while prev:
            if head.val != prev.val:
                return False
            head = head.next
            prev = prev.next
        return True
```

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        list_vals = []
        while head:
            list_vals.append(head.val)
            head = head.next
        
        left, right = 0, len(list_vals) - 1
        while left < right and list_vals[left] == list_vals[right]:
            left += 1
            right -= 1
        return left >= right
```
