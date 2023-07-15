# [1218. Longest Arithmetic Subsequence of Given Difference](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/)

## description

Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

Example 1:

```python
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
```

Example 2:

```python
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.
```

Example 3:

```python
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
```

Constraints:


- 1 <= arr.length <= 10^5



- -10^4 <= arr[i], difference <= 10^4


## idea

1 brute force

2 dp

``` cpp
//unable for large data
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int pre = 0;
        int res = 1;
        int sub = 1;
        for(int i = 0; i < arr.size(); i++) {
            pre = i;
            sub = 1;
            for (int j = i+1; j < arr.size(); j++) {
                if(arr[pre] + difference == arr[j]) {
                    pre = j;
                    sub++;
                }
            }
            // cout << i << " " << sub << endl;
            res = max(res, sub);
        }
        return res;
    }
};
```

3 hash map

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int> dp(arr.size(), 0);
        unordered_map<int, int> umap;
        int res = 1;
        for (auto ar : arr) {
            if (umap.find(ar-difference) != umap.end()){
                umap[ar] = umap[ar-difference] + 1;
            } else{
                umap[ar] = 1;
            }
            res = max(res, umap[ar]);
        }
        return res;
    }
}
```