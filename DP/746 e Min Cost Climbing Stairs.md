You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

example 1\
```
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
```

example 2\
```
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```

Idea:\
```cpp
dp[0] = 0;
dp[1] = 0;
dp[2] = cost[0] or cost[1];
      = dp[1] + cost[1] or dp[0] + cost[0];
dp[3] = dp[2] + cost[2] or dp[1] + cost[1];
dp[4] = dp[3] + cost[3] or dp[2] + cost[2];
dp[i] = dp[i-1] + cost[i-1] or dp[i-2] + cost[i-2];
```
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2);
        if (cost.size() == 2) {
            return cost[0] < cost[1] ? cost[0]: cost[1];
        } else if (cost.size() == 3) {
            return (cost[0] + cost[2]) < cost[1] ? (cost[0] + cost[2]): cost[1];
        } else {
            dp[2] = cost[0] < cost[1] ? cost[0]: cost[1];
            dp[3] = dp[2] + cost[2] < cost[1] ? dp[2] + cost[2]: cost[1];
            for (int i = 4; i< cost.size()+1; i++) {
                dp[i] = dp[i-1]+cost[i-1] < dp[i-2]+cost[i-2]? dp[i-1]+cost[i-1] : dp[i-2]+cost[i-2];
                cout << dp[i] << endl;
            }
            return dp[cost.size()];
        }
    }
};
```











