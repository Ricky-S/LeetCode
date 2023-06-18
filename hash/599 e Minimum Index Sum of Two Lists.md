# [599. Minimum Index Sum of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/)

## description

Given two arrays of strings list1 and list2, find the common strings with the least index sum.

A common string is a string that appeared in both list1 and list2.

A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.

Return all the common strings with the least index sum. Return the answer in any order.

**Example 1:**

```text

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]

Output: ["Shogun"]

Explanation: The only common string is "Shogun".

```

**Example 2:**

```text
Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
```

**Example 3:**

```text
Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
Output: ["sad","happy"]
Explanation: There are three common strings:
"happy" with index sum = (0 + 1) = 1.
"sad" with index sum = (1 + 0) = 1.
"good" with index sum = (2 + 2) = 4.
The strings with the least index sum are "sad" and "happy".
```

**Constraints:**

- 1 <= list1.length, list2.length <= 1000
- 1 <= list1[i].length, list2[i].length <= 30
- list1[i] and list2[i] consist of spaces ' ' and English letters.
- All the strings of list1 are unique.
- All the strings of list2 are unique.
- There is at least a common string between list1 and list2.

Idea:

1. hash table


## Solution:

```cpp
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); i++) m[list1[i]] = i;
        vector<string> res;
        int minSum = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (m.count(list2[i])) {
                int sum = i + m[list2[i]];
                if (sum < minSum) {
                    res.clear();
                    res.push_back(list2[i]);
                    minSum = sum;
                } else if (sum == minSum) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};
```

My solution:

```cpp
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> umap;
        for(int i = 0; i < list1.size(); i++) umap[list1[i]] = i;
        int min = INT_MAX;
        vector<string>res;
        for(int i = 0; i < list2.size(); i++)
            if(umap.count(list2[i]) != 0)
                if(umap[list2[i]] + i < min) {
                    min = umap[list2[i]] + i, res.clear(), res.push_back(list2[i]);
                }
                else if(umap[list2[i]] + i == min) res.push_back(list2[i]);
        return res;       
    }
};
```