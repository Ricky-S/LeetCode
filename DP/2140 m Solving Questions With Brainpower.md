# [2140. Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower/description/?envType=daily-question&envId=2025-04-01)


## Description

You are given a **0-indexed** 2D integer array `questions` where `questions[i] = [pointsi, brainpoweri]`.

The array describes the questions of an exam, where you have to process the questions **in order** (i.e., starting from question `0`) and make a decision whether to **solve** or **skip** each question. Solving question `i` will **earn** you `pointsi` points but you will be **unable** to solve each of the next `brainpoweri` questions. If you skip question `i`, you get to make the decision on the next question.

- For example, given `questions = [[3, 2], [4, 3], [4, 4], [2, 5]]`:
    - If question `0` is solved, you will earn `3` points but you will be unable to solve questions `1` and `2`.
    - If instead, question `0` is skipped and question `1` is solved, you will earn `4` points but you will be unable to solve questions `2` and `3`.

Return *the **maximum** points you can earn for the exam*.

**Example 1:**

```
Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

```

**Example 2:**

```
Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

```

**Constraints:**

- `1 <= questions.length <= 105`
- `questions[i].length == 2`
- `1 <= pointsi, brainpoweri <= 105`

Idea:\
```cpp
dp[i]

questions = [[3,2],[4,3],[4,4],[2,5]]

dp[0] = max(dp[1], 3 + dp[0+(2+1)]), which means we need to find dp[1] and dp[3].
dp[1] = max(dp[2], 4 + dp[1+(3+1)]), which means we need to find dp[2] and dp[5], but dp[5] is out of range, dp[>vector.size] = 0.
dp[2] = max(dp[3], 4 + dp[2+(4+1)]), which means we need to find dp[3] and dp[7], but dp[7] is out of range, dp[>vector.size] = 0.
dp[3] = max(dp[4], 5 + dp[3+(5+1)]), which means we need to find dp[4] and dp[9], but dp[4] and dp[9] are out of range, dp[>vector.size] = 0.
dp[i] = max(dp[i+1], questions[i][0] + dp[i+(questions[i][1]+1)], i and i+(questions[i][1]+1) are < vector.size.
explanation: dp[i+1] means we skip question i, and dp[i+(questions[i][1]+1)] means we solve question i, and we need to find the next question we can solve.
```


```cpp
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int size = questions.size();
        vector<long long> dp(size+1, 0);
        for ( int i = size - 1; i>=0; i--) {
            if (questions[i][1]+i+1 < size) dp[i] = max((long long)questions[i][0] + dp[questions[i][1]+i+1], dp[i+1]);
            else dp[i] = max((long long)questions[i][0] + 0, dp[i+1]);
            // cout << i << endl;
        }
        return dp[0];
    }
};
```


```python
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)

        dp = [0] * n

        dp[n-1] = questions[n-1][0]

        for i in range(n-2, -1, -1):
            points, brain = questions[i]

            next_i = i + brain + 1
            solve_points = points + (dp[next_i] if next_i < n else 0)

            dp[i] = max(solve_points, dp[i+1])
        return dp[0]
```








