# [178. Rank Scores](https://leetcode.com/problems/rank-scores/description/)


## Description

Table: `Scores`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains the score of a game. Score is a floating point value with two decimal places.
```

Write a solution to find the rank of the scores. The ranking should be calculated according to the following rules:

The scores should be ranked from the highest to the lowest.
If there is a tie between two scores, both should have the same ranking.
After a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no holes between ranks.
Return the result table ordered by score in descending order.

The result format is in the following example.

Example 1:

```
Input: 
Scores table:
+----+-------+
| id | score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
Output: 
+-------+------+
| score | rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+
```


## Solution

[explaination](https://leetcode.com/problems/rank-scores/solutions/3861595/pandas-simple-2-step-approach-additional-knowledge-at-the-end/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata)

'average' (default): This method assigns the average rank to tied elements. For example, if two elements tie for the second rank, they both get the rank of 2.5, and the next rank will be 4.

'min': This method assigns the minimum rank to tied elements. For example, if two elements tie for the second rank, they both get the rank of 2, and the next rank will be 4.

'max': This method assigns the maximum rank to tied elements. For example, if two elements tie for the second rank, they both get the rank of 3, and the next rank will be 4.

'first': This method assigns ranks in the order they appear in the input data, without using any average or other calculations for ties. For example, if two elements tie for the second rank, the first element gets the rank of 2, and the next rank will be 4.

'dense': This method assigns dense ranks to tied elements, meaning there are no gaps in the ranks. For example, if two elements tie for the second rank, they both get the rank of 2, and the next rank will be 3.

'ordinal': This method is similar to 'dense', but it considers the order of appearance in the data for assigning ranks to tied elements. For example, if two elements tie for the second rank, the first element gets the rank of 2, and the next rank will be 3.


```python
import pandas as pd

def rank_scores(scores: pd.DataFrame) -> pd.DataFrame:
    # pd.rank(method='average', numeric_only=None, na_option='keep', ascending=True, pct=False)
    # method: average, min, max, first, dense
    # numeric_only: For DataFrame objects, a string indicating whether to rank using the row/column labels or numeric values.
    # na_option: keep, top, bottom
    # ascending: True, False
    # pct: If True, compute percentage rank of data.
    scores['rank'] = scores['score'].rank(method='dense', ascending=False).astype(int)

    sorted_df = scores.sort_values(by='score', ascending=False)

    return sorted_df[['score', 'rank']]
```


