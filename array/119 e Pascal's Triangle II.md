Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

![figure](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)



Example 1:
```
Input: rowIndex = 3
Output: [1,3,3,1]
```

Example 2:
```
Input: rowIndex = 0
Output: [1]
```

Example 2:
```
Input: rowIndex = 1
Output: [1,1]
```

idea:
for rows larger than 3, every number[i] = previous_row[i-1]+previous_row[i].


```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> result;        
        if (rowIndex < 2) {
            return vector<int> (rowIndex+1, 1);
        } else {
            result.push_back({1});
            result.push_back({1, 1});
            for (int i = 2; i <=rowIndex; i++) {
                vector<int> temp(i+1, 1);
                for (int j =1; j < i; j++) {
                    temp[j] = result[i-1][j-1] + result[i-1][j];
                    cout<< "i" << i << "j" << j << "temp[j]" << temp[j] << endl;
                }
                
                result.push_back(temp);
            }
            return result[rowIndex];
        }
    }
};
```
