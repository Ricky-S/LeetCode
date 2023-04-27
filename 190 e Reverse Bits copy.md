# 191. Number of 1 Bits

Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

ex1
```cpp
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
```

ex2
```cpp
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
```

ex3
```cpp
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
```

Constraints\
```cpp
The input must be a binary string of length 32.
```

idea:\
use bit to calculate.

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        cout << n << endl;
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (((n>>i) & 1) == 1) count ++;
        }
        return count;
    }
};
```










