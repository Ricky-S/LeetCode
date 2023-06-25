7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


Example 1:
```cpp
Input: x = 123
Output: 321
```

Example 2:
```cpp
Input: x = -123
Output: -321
```
ex3\
```cpp
Input: x = 120
Output: 21
```

idea:
it may exceed the INT_MAX or INT_MIN.\
But we need to think what if we cannot use long long type.\
int     2 or 4 bytes	\
long	4 bytes\
longlong 8bytes

```c++
class Solution {
public:
    int reverse(int x) {
        vector<int> xDetails;
        long long result = 0;

        long long xAbs;
        if (x>=0) xAbs = x;
        else {
            xAbs = -(x+1);
            xAbs++;        
        }
        cout << xAbs << endl;
        while ( xAbs > 0 ) {
            
            xDetails.push_back(xAbs % 10);
            cout << xAbs % 10 << endl;
            // intCount++;
            xAbs = xAbs / 10;
        }
        for (int i = 0; i < xDetails.size(); i++) {
            result = result + xDetails[i]*pow(10, xDetails.size()-i-1);
        }
        if (result > INT_MAX) return 0;
        else if (result < INT_MIN) return 0;
        else {
            return x>=0? int(result): -int(result);
        }

        
    }
};
```
