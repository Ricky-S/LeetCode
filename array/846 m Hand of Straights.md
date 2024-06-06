# [846. Hand of Straights](https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06)

## Description

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size `groupSize`, and consists of `groupSize` consecutive cards.

Given an integer array `hand` where `hand[i]` is the value written on the `ith` card and an integer `groupSize`, return `true` if she can rearrange the cards, or `false` otherwise.

**Example 1:**

```
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

```

**Example 2:**

```
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

```

**Constraints:**

- `1 <= hand.length <= 104`
- `0 <= hand[i] <= 109`
- `1 <= groupSize <= hand.length`

**Note:** This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

## Solution

```python
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        hand.sort()
        counter = collections.Counter(hand)
        for card in hand:
            if counter[card] == 0:
                continue
            for i in range(groupSize):
                if counter[card + i] == 0:
                    return False
                counter[card + i] -= 1
        return True
```

OR

```python
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand.sort()
        print(hand)
        dic = defaultdict(int)
        for i in hand:
            dic[i] = dic.get(i, 0) + 1
        for card in hand:
            if dic[card] > 0:
                for i in range(groupSize):
                    if dic[card + i] > 0:
                        dic[card + i] -= 1
                    else:
                        return False
        return True
```