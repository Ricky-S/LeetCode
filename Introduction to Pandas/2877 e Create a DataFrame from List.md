# [2877. Create a DataFrame from List](https://leetcode.com/problems/create-a-dataframe-from-list/?envType=study-plan-v2&envId=introduction-to-pandas&lang=pythondata)

## Description

Write a solution to **create** a DataFrame from a 2D list called `student_data`. This 2D list contains the IDs and ages of some students.

The DataFrame should have two columns, `student_id` and `age`, and be in the same order as the original 2D list.

The result format is in the following example.

**Example 1:**

```
Input:
student_data:[
  [1, 15],
  [2, 11],
  [3, 11],
  [4, 20]
]Output:
+------------+-----+
| student_id | age |
+------------+-----+
| 1          | 15  |
| 2          | 11  |
| 3          | 11  |
| 4          | 20  |
+------------+-----+
Explanation:
A DataFrame was created on top of student_data, with two columns namedstudent_id andage.
```

## Solution

```python
import pandas as pd

def create_dataframe(student_data):
    # Write your solution here
    df = pd.DataFrame(student_data, columns=['student_id', 'age'])
    return df
```