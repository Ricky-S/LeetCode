# [570. Managers with at Least 5 Direct Reports](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata)


## Description

Table: Employee
```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.
 ```

Write a solution to find managers with at least five direct reports.

Return the result table in any order.

The result format is in the following example.

 

Example 1:
```
Input: 
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | None      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
Output: 
+------+
| name |
+------+
| John |
+------+
```

## Solution 

[explanation](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/solutions/3970307/pandas-very-intutive-approach-commented-code/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata)

```python
import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    manager_report_count = employee.groupby('managerId').size().reset_index(name='directReports')

    # Filter managers with at least five direct reports
    result = manager_report_count[manager_report_count['directReports'] >= 5]


    # must use inner, if use left, may get null values:
#     | id  | name  | department | managerId |
# | --- | ----- | ---------- | --------- |
# | 101 | John  | A          | null      |
# | 102 | Dan   | A          | 100       |
# | 103 | James | A          | 100       |
# | 104 | Amy   | A          | 100       |
# | 105 | Anne  | A          | 100       |
# | 106 | Ron   | B          | 100       |
    result = result.merge(employee, left_on='managerId', right_on='id', how='inner')
    # print(result)
    return result[['name']]
```


