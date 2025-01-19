# [2889. Reshape Data: Pivot](https://leetcode.com/problems/reshape-data-pivot/description/?envType=study-plan-v2&envId=introduction-to-pandas&lang=pythondata)

## Description

```
DataFrame weather
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| city        | object |
| month       | object |
| temperature | int    |
+-------------+--------+
```

Write a solution to pivot the `weather` table such that the `city` is the first column and the `months` are the new columns. The `temperature` values are the value of the new table.

The result format is in the following example.

### Example 1:

```
Example 1:
Input:
+--------------+----------+-------------+
| city         | month    | temperature |
+--------------+----------+-------------+
| Jacksonville | January  | 13          |
| Jacksonville | February | 23          |
| Jacksonville | March    | 38          |
| Jacksonville | April    | 5           |
| Jacksonville | May      | 34          |
| ElPaso       | January  | 20          |
| ElPaso       | February | 6           |
| ElPaso       | March    | 26          |
| ElPaso       | April    | 2           |
| ElPaso       | May      | 43          |
+--------------+----------+-------------+
Output:
+----------+--------+--------------+
| month    | ElPaso | Jacksonville |
+----------+--------+--------------+
| April    | 2      | 5            |
| February | 6      | 23           |
| January  | 20     | 13           |
| March    | 26     | 38           |
| May      | 43     | 34           |
+----------+--------+--------------+
Explanation:
The table is pivoted, each column represents a city, and each row represents a specific month.
```
[More information about pivot](https://pandas.pydata.org/docs/reference/api/pandas.DataFrame.pivot.html)

## Solution

```python
import pandas as pd

def pivot_table(weather):
    return weather.pivot(index='month', columns='city', values='temperature')

```