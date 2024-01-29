# [2887. Fill Missing Data](https://leetcode.com/problems/fill-missing-data/description/?envType=study-plan-v2&envId=introduction-to-pandas&lang=pythondata)

## Description

```
DataFrame products
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| name        | object |
| quantity    | int    |
| price       | int    |
+-------------+--------+
```

Write a solution to fill in the missing value as 0 in the quantity column.

The result format is in the following example.

### Example 1:

```
Example 1:
Input:+-----------------+----------+-------+
| name            | quantity | price |
+-----------------+----------+-------+
| Wristwatch      | None     | 135   |
| WirelessEarbuds | None     | 821   |
| GolfClubs       | 779      | 9319  |
| Printer         | 849      | 3051  |
+-----------------+----------+-------+
Output:
+-----------------+----------+-------+
| name            | quantity | price |
+-----------------+----------+-------+
| Wristwatch      | 0        | 135   |
| WirelessEarbuds | 0        | 821   |
| GolfClubs       | 779      | 9319  |
| Printer         | 849      | 3051  |
+-----------------+----------+-------+
Explanation: 
The quantity for Wristwatch and WirelessEarbuds are filled by 0.
```


## Solution

```python

import pandas as pd

def fillMissingData(products):
    products['quantity'] = products['quantity'].fillna(0)
    return products

```

```python

import pandas as pd

def fillMissingData(products: pd.DataFrame) -> pd.DataFrame:
    return products.fillna(0)

```

