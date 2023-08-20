# [1148. Article Views I](https://leetcode.com/problems/article-views-i/)

## Description

Table: `Views`
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
The table may have duplicate rows (In other words, there is no primary key for this table in SQL).
Each row of this table indicates that some viewer viewed an article (written by some author) on some date. 
Note that equal author_id and viewer_id indicate the same person.
```

Find all the authors that viewed at least one of their own articles.

Return the result table sorted by id in ascending order.

The result format is in the following example.


Example 1:
```
Input: 
Views table:
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+
Output: 
+------+
| id   |
+------+
| 4    |
| 7    |
+------+
```

## Solution

```sql
# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id ASC
```

[pandas solution](https://leetcode.com/problems/article-views-i/solutions/3852944/pandas-my-sql-very-simple-with-approach-and-explanation/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata)

```python
import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    same_pd = views[(views['author_id'] == views['viewer_id'])]['viewer_id'].unique()
    same_pd = sorted(same_pd)
    return pd.DataFrame({'id': same_pd})
```

```python
import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    # Filter rows where author_id and viewer_id are the same (authors viewing their own articles)
    authors_viewed_own_articles = views[views['author_id'] == views['viewer_id']]
    
    # Get unique author_ids from the filtered data
    unique_authors = authors_viewed_own_articles['author_id'].unique()
    
    # Sort the unique author_ids in ascending order
    unique_authors = sorted(unique_authors)
    
    # Create a DataFrame with the sorted unique author_ids and rename the 'author_id' column to 'id'
    result_df = pd.DataFrame({'id': unique_authors})
    
    return result_df
```