# [2551. Put Marbles in Bags](https://leetcode.com/problems/put-marbles-in-bags/description/)

## description

You have `k` bags. You are given a **0-indexed** integer array `weights` where `weights[i]` is the weight of the `ith` marble. You are also given the integer `k`.

Divide the marbles into the `k` bags according to the following rules:

- No bag is empty.


- If the `ith` marble and `jth` marble are in a bag, then all marbles with an index between the `ith` and `jth` indices should also be in that same bag.


- If a bag consists of all the marbles with an index from `i` to `j` inclusively, then the cost of the bag is `weights[i] + weights[j]`.



The **score** after distributing the marbles is the sum of the costs of all the `k` bags.

*Return the **difference** between the **maximum** and **minimum** scores among marble distributions.*


Example 1:

```text
Input: weights = [1,3,5,1], k = 2
Output: 4
Explanation: 
The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6. 
The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10. 
Thus, we return their difference 10 - 6 = 4.
```

Example 2:

```text
Input: weights = [1, 3], k = 2
Output: 0
Explanation: The only distribution possible is [1],[3]. 
Since both the maximal and minimal score are the same, we return 0.
```

Constraints:

- `1 <= k <= weights.length <= 10^5`


- `1 <= weights[i] <= 10^9`


## Solution

We can't find all possible bags. So we need to find all possible positions.

1. if one bag or length(weights)-1 bags, the max and min should be the same, since only one solution. return 0.
2. if two bags, we need to find only one position to divide the list. Suppose position is `i`, then the score is `weights[0]+weights[i]` and `weights[i+1]+weights[-1]`. So the sum will be `weights[0]+weights[i]+weights[i+1]+weights[-1]`. we need to find all possible `i` to get the max and min. 
3. Three bags are the same. We need to find two positions `i` and `j` to divide the list. The sum will be `weights[0]+weights[i]+weights[i+1]+weights[j]+weights[j+1]+weights[-1]`. We need to find all possible `i` and `j` to get the max and min.

```c++
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1 || k == weights.size()) return 0;
        vector<int> neiborSum;
        for (int i = 0; i < weights.size()-1; i++) {
            neiborSum.push_back(weights[i] + weights[i+1]);
        }
        // cout << neiborSum.size() << endl;
        sort(neiborSum.begin(), neiborSum.end());
        for (int i : neiborSum) {
            cout << i << endl;
        }
        long long minSum = 0;
        long long maxSum = 0;
        for (int i = 0; i < k-1; i++) {
            cout << neiborSum[i] << endl;
            minSum += neiborSum[i];
            maxSum += neiborSum[(neiborSum.size()-1)-i];
        }        
        return maxSum-minSum;
    }
};
```

```python
class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        # print(len(weights))
        neighborSum = []
        minSum = 0
        maxSum = 0
        res = 0
        if k == 1 or k == len(weights):
            return 0
        else:
            for i in range(len(weights)-1):
                neighborSum.append(weights[i]+weights[i+1])
            # print(neighborSum)
            neighborSum.sort()
            # print(neighborSum)
            for i in range(k-1):
                minSum += neighborSum[i]
                maxSum += neighborSum[len(neighborSum)-1-i]
            return maxSum - minSum
```