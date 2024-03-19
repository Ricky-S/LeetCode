# [59. Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)

## Description

Given a positive integer n, generate an $n * n$ matrix filled with elements from 1 to $n^2$ in spiral order.

![image](https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg)\
Example 1:
```
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
```

Example 2:
```
Input: n = 1
Output: [[1]]
```

Idea:\
if n = 3, 1,2| 3 4| 5 6| 7 8| center \
if n = 4 \
1  2  3  4 \
12 13 14 5 \
11 16 15 6 \
10 9  8  7\


$O(n^2)$
```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n,0));
        
        int size = n / 2;
        int add = 0;
        int i, j;
        int istart = 0, iend = n - 1;
        int jstart = 0, jend = n - 1;

        while(size > 0) 
        {
            i = istart;
            j = jstart;
            for (i = istart; i < iend; i++) {
                add++;
                mat[j][i] = add;
                cout << add <<"i" << i << endl;
            }
            for (j = jstart; j < jend; j++) {
                add++;
                mat[j][i] = add;
                cout << add <<"j" << j << endl;
            }
            for (; i > istart; i--) {
                add++;
                mat[j][i] = add;
                cout << add <<"i" << i <<  endl;
            }
            for (; j > jstart; j--) {
                add++;
                mat[j][i] = add;
                cout << add <<"j" << j <<  endl;
            }   
            istart++;
            jstart++;   
            iend--;
            jend--;  
            size = size - 1;                
        }


        if(n%2 == 1) {
            int center = n/2;
            mat[center][center] = n*n;
        }

        return mat;

    }
};
```

```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        mat = [[0 for _ in range(n)] for _ in range(n)]
        size = n // 2
        add = 0
        istart, iend = 0, n - 1
        jstart, jend = 0, n - 1
        while size > 0:
            i, j = istart, jstart
            while i < iend:
                add += 1
                mat[j][i] = add
                i += 1
            while j < jend:
                add += 1
                mat[j][i] = add
                j += 1
            while i > istart:
                add += 1
                mat[j][i] = add
                i -= 1
            while j > jstart:
                add += 1
                mat[j][i] = add
                j -= 1
            istart += 1
            jstart += 1
            iend -= 1
            jend -= 1
            size -= 1
        if n % 2 == 1:
            center = n // 2
            mat[center][center] = n * n
        return mat
``` 





















