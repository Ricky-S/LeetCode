# [14. Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

## Description

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

Example 2:

```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```

Constraints:

- 1 < prices.length <= 5 * 10^4
- 1 < prices[i] < 5 * 10^4
- 0 < fee < 5 * 10^4


Ideas：

- DP
  

Solution:

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
```


```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(2, 0);
        dp[0] = 0;
        dp[1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[0] = max(dp[0], dp[1] + prices[i] - fee);
            dp[1] = max(dp[1], dp[0] - prices[i]);
        }
        return dp[0];
    }
};
```

My Solution:

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long profitPre = 0, profitTod = INT_MIN;

        for (int price : prices) {
            int tempPre = profitPre;
            profitPre = std::max<long long int> (profitPre, profitTod + price - fee);
            profitTod = std::max<long long int> (profitTod, tempPre - price);
        }
        return (int)profitPre;
    }
};
```
