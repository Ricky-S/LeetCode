# [1980. Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08)

## Description

Given an array of strings `nums` containing `n` **unique** binary strings each of length `n`, return *a binary string of length* `n` *that **does not appear** in* `nums`*. If there are multiple answers, you may return **any** of them*.

**Example 1:**

```
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
```

**Example 2:**

```
Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
```

**Example 3:**

```
Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
```

**Constraints:**

- `1 <= nums.length <= 16`
- `nums[i].length == n`
- `nums[i]` is either `'0'` or `'1'`.
- All the strings of `nums` are unique.

## Solution

```python
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        return ''.join('1' if num[i] == '0' else '0' for i, num in enumerate(nums))
```


```python
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        d = set(nums)
        start = 0
        for i in range(2 ** n):
            # print(bin(i)[2:].zfill(n))
            if bin(i)[2:].zfill(n) not in d:
                return bin(i)[2:].zfill(n)
```