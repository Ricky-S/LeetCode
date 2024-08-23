# [592. Fraction Addition and Subtraction](https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23)

## Description

Given a string `expression` representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an [irreducible fraction](https://en.wikipedia.org/wiki/Irreducible_fraction). If your final result is an integer, change it to the format of a fraction that has a denominator `1`. So in this case, `2` should be converted to `2/1`.

**Example 1:**

```
Input: expression = "-1/2+1/2"
Output: "0/1"

```

**Example 2:**

```
Input: expression = "-1/2+1/2+1/3"
Output: "1/3"

```

**Example 3:**

```
Input: expression = "1/3-1/2"
Output: "-1/6"

```

**Constraints:**

- The input string only contains `'0'` to `'9'`, `'/'`, `'+'` and `'-'`. So does the output.
- Each fraction (input and output) has the format `±numerator/denominator`. If the first input fraction or the output is positive, then `'+'` will be omitted.
- The input only contains valid **irreducible fractions**, where the **numerator** and **denominator** of each fraction will always be in the range `[1, 10]`. If the denominator is `1`, it means this fraction is actually an integer in a fraction format defined above.
- The number of given fractions will be in the range `[1, 10]`.
- The numerator and denominator of the **final result** are guaranteed to be valid and in the range of **32-bit** int.


## Solution

```python
class Solution:
    def fractionAddition(self, expression: str) -> str:
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        def lcm(a, b):
            return a * b // gcd(a, b)

        def add(a, b):
            a1, a2 = a
            b1, b2 = b
            l = lcm(a2, b2)
            return (a1 * l // a2 + b1 * l // b2, l)

        def reduce(a):
            a1, a2 = a
            g = gcd(a1, a2)
            return (a1 // g, a2 // g)

        def parse(s):
            a, b = s.split('/')
            return (int(a), int(b))

        if expression[0] != '-':
            expression = '+' + expression
        expression = expression.replace('-', '+-')
        expression = expression.split('+')
        expression = [parse(e) for e in expression if e]

        res = (0, 1)
        for e in expression:
            res = add(res, e)
        res = reduce(res)
        return f'{res[0]}/{res[1]}'
```

```python
from fractions import Fraction

class Solution:
    def fractionAddition(self, expression: str) -> str:
        expression = expression.replace('-', '+-')
        fractions = expression.split('+')
        # print(fractions)
        res = 0
        for fraction in fractions:
            if fraction:
                res += Fraction(fraction)
        # print(res)
        return f"{res.numerator}/{res.denominator}"
```