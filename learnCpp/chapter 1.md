# [LEARN C++](https://www.learncpp.com/)


## 1.2 — Comments
At the library, program, or function level, use comments to describe what.\
Inside the library, program, or function, use comments to describe how.\
At the statement level, use comments to describe why.

## 1.4 — Variable assignment and initialization
**Best practice** 
+ **Favor initialization using braces.**
+ **Initialize your variables upon creation.**





```cpp
// Best practice
// Favor initialization using braces.

int a;         // no initializer (default initialization)
int b = 5;     // initializer after equals sign (copy initialization)

// One of the reasons direct initialization has fallen out of favor is because it makes it hard to differentiate variables from functions.
int c( 6 );    // initializer in parenthesis (direct initialization)

// List initialization methods (C++11) (preferred)
int d { 7 };   // initializer in braces (direct list initialization)
int e = { 8 }; // initializer in braces after equals sign (copy list initialization)

// In most cases, value initialization will initialize the variable to zero (or empty, if that’s more appropriate for a given type). In such cases where zeroing occurs, this is called zero initialization.
int f {};      // initializer is empty braces (value initialization) / zero initialization to value 0
```