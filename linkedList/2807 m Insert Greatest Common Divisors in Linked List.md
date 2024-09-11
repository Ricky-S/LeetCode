# [2807. Insert Greatest Common Divisors in Linked List](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10)

## Description

Given the head of a linked list `head`, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the **greatest common divisor** of them.

Return *the linked list after insertion*.

The **greatest common divisor** of two numbers is the largest positive integer that evenly divides both numbers.

**Example 1:**

!https://assets.leetcode.com/uploads/2023/07/18/ex1_copy.png

```
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.

```

**Example 2:**

!https://assets.leetcode.com/uploads/2023/07/18/ex2_copy1.png

```
Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.

```

**Constraints:**

- The number of nodes in the list is in the range `[1, 5000]`.
- `1 <= Node.val <= 1000`


## Solution

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# class Solution:
#     def insertGCD(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         def gcd(a, b):
#             while b:
#                 a, b = b, a % b
#             return a

#         dummy_head = ListNode(0)
#         dummy_head.next = head
#         cur = dummy_head
#         while cur.next and cur.next.next:
#             a, b = cur.next.val, cur.next.next.val
#             g = gcd(a, b)
#             if g > 1:
#                 cur.next.next = ListNode(g, cur.next.next)
#             cur = cur.next
#         return dummy_head.next
```

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        node1 = head
        while node1.next:
            temp1 = node1.val
            temp2 = node1.next.val
            while temp2:
                temp1, temp2 = temp2, temp1 % temp2
            temp = ListNode(temp1)
            node2 = node1.next
            node1.next = temp
            temp.next = node2
            node1 = node2
        
        return head
```