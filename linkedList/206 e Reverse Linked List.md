Given the head of a singly linked list, reverse the list, and return the reversed list.


Example 1:\
![image](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)\

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

Example 2:\
![image](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)
```
Input: head = [1,2]
Output: [2,1]
```

Example 3:
```
Input: head = []
Output: []
```


Idea:\
![image](https://camo.githubusercontent.com/9e604579b33a236aad08d105b68cc2bab10d8b24d5d34a20536a732389f3979b/68747470733a2f2f636f64652d7468696e6b696e672e63646e2e626365626f732e636f6d2f676966732f3230362e2545372542462542422545382542442541432545392539332542452545382541312541382e676966)
[link](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.md)


$O(n)$
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return {};
        } else {
            ListNode* temp = head;
            ListNode* cur = head;
            ListNode* result(nullptr);
            while (cur != nullptr) {
                temp = cur->next;
                cur->next = result;
                result = cur;
                cur = temp;
            }
            return result;
        }
    }
};
```

























