# [1683. Invalid Tweets](https://leetcode.com/problems/invalid-tweets/)

## Description

<p>Table: <code>Tweets</code></p>

<pre>+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| tweet_id       | int     |
| content        | varchar |
+----------------+---------+
tweet_id is the primary key for this table.
This table contains all the tweets in a social media app.
</pre>

<p>&nbsp;</p>


Find the IDs of the invalid tweets. The tweet is invalid if the number of characters used in the content of the tweet is strictly greater than 15.

Return the result table in any order.

The result format is in the following example.


Example 1:

```
Input: 
Tweets table:
+----------+----------------------------------+
| tweet_id | content                          |
+----------+----------------------------------+
| 1        | Vote for Biden                   |
| 2        | Let us make America great again! |
+----------+----------------------------------+
Output: 
+----------+
| tweet_id |
+----------+
| 2        |
+----------+
Explanation: 
Tweet 1 has length = 14. It is a valid tweet.
Tweet 2 has length = 32. It is an invalid tweet.
```


## Solution

```SQL
# Write your MySQL query statement below
select tweet_id
from Tweets
where length(content) > 15
```

```sql
/* Write your T-SQL query statement below */
select tweet_id
from Tweets
where len(content) > 15
```

```python
import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    invalid = tweets[(tweets['content'].str.len() > 15)]
    return invalid[['tweet_id']]

```

```python
import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    return tweets[tweets['content'].str.len() > 15][['tweet_id']]
```
