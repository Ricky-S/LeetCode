# [197. Rising Temperature](https://leetcode.com/problems/rising-temperature/)

## Description

Table: Weather
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
In SQL, id is the primary key for this table.
This table contains information about the temperature on a certain day.
```

Find all dates' Id with higher temperatures compared to its previous dates (yesterday).

Return the result table in any order.

The result format is in the following example.

Example 1:
```
Input: 
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output: 
+----+
| id |
+----+
| 2  |
| 4  |
+----+
Explanation: 
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).
```


## Solution

```sql
SELECT w1.id
FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature
AND TO_DAYS(w1.RecordDate) - TO_DAYS(w2.RecordDate) = 1
```

```sql
# Write your MySQL query statement below
select w2.id
from Weather w1, Weather w2
where w2.temperature  > w1.temperature  and datediff(w2.recordDate, w1.recordDate) = 1
```

[sols](https://leetcode.com/problems/rising-temperature/solutions/2386995/three-different-solutions-datediff-subdate/?envType=study-plan-v2&envId=top-sql-50)
```sql
# 1.
SELECT w2.id from Weather w1,Weather w2
WHERE datediff(w2.recordDate, w1.recordDate) = 1 AND w2.temperature > w1.temperature;
// where datediff -> date difference b/w two dates
# 2.
SELECT w2.id from Weather w1, Weather w2
WHERE w2.temperature > w1.temperature AND
subdate(w2.recordDate, 1) = w1.recordDate;
// where subdate -> subtract date 

#3.
SELECT w2.id from Weather w1 JOIN Weather w2
ON w2.temperature > w1.temperature AND
datediff(w2.recordDate,w1.recordDate) = 1;
```