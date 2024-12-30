# [2883. Drop Missing Data](https://leetcode.com/problems/drop-missing-data/description/?envType=study-plan-v2&envId=introduction-to-pandas&lang=pythondata)

## Description

```
DataFrame students
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
+-------------+--------+
```

There are some rows having missing values in the `name` column.

Write a solution to remove the rows with missing values.

The result format is in the following example.

### Example 1:

```
Input:
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 32         | Piper   | 5   |
| 217        | None    | 19  |
| 779        | Georgia | 20  |
| 849        | Willow  | 14  |
+------------+---------+-----+
Output:
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 32         | Piper   | 5   |
| 779        | Georgia | 20  | 
| 849        | Willow  | 14  | 
+------------+---------+-----+
Explanation: 
Student with id 217 havs empty value in the name column, so it will be removed.
```


Here's the general usage of the `dropna` function:

```python
DataFrame.dropna(axis=0, how='any', thresh=None, subset=None, inplace=False)
```

**`dropna` Function Argument Definition:**

1. `axis`: It can be `{0 or 'index', 1 or 'columns'}`. By default it's `0`. If `axis=0`, it drops rows which contain missing values, and if `axis=1`, it drops columns which contain missing value.
2. `how`: Determines if row or column is removed from DataFrame, when we have at least one NA or all NA.
    - `how='any'` : If any NA values are present, drop that row or column (default).
    - `how='all'` : If all values are NA, drop that row or column.
3. `thresh`: Require that many non-NA values. This is an integer argument which requires a minimum number of non-NA values to keep the row/column.
4. `subset`: Labels along the other axis to consider, e.g. if you are dropping rows these would be a list of columns to include. This is particularly useful when you only want to consider NA values in certain columns.
5. `inplace`: It's a boolean which makes the changes in data frame itself if `True`. Always remember when using the `inplace=True` argument, you're modifying the original DataFrame. If you need to retain the original data for any reason, avoid using `inplace=True` and instead assign the result to a new DataFrame.



## Solution

```python

import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students.dropna(subset=['name'])
```


```python
import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students.dropna(subset=['name'])
```
```python