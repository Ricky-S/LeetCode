# 605. Can Place Flowers

## Description:
<p>You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.</p>

<p>Given an integer array <code>flowerbed</code> containing <code>0</code>'s and <code>1</code>'s, where <code>0</code> means empty and <code>1</code> means not empty, and an integer <code>n</code>, return <em>if</em> <code>n</code> new flowers can be planted in the <code>flowerbed</code> without violating the no-adjacent-flowers rule.</p>

example 1
```
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
```

example 2
```
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

Constraints:
```
1 <= flowerbed.length <= 2 * 10^4
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
```

## Idea:
1. if the current position is 0, check the previous and next position, if both of them are 0, then we can plant a flower.


## Solution:
```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (flowerbed[0]) {
                if (n == 0) return true;
                else return false;                
            } else {
                if (n > 1) return false;
                else return true;
            }
        }
        else if (flowerbed.size() == 2) {
            if (flowerbed[0] || flowerbed[1]) {
                if (n == 0) return true;
                else return false;                
            } else {
                if (n > 1) return false;
                else return true;
            }
        }

        int res = 0;
        if ((flowerbed[0] == 0) && flowerbed[1] == 0) {
            res++;
            flowerbed[0] = 1;
        }

        for (int i = 1; i < flowerbed.size()-2; i++) {
            if((flowerbed[i-1] == 0) && (flowerbed[i] == 0) && (flowerbed[i+1] == 0)) {
                res++;
                flowerbed[i] = 1;               
            }
        }
        if ((flowerbed[flowerbed.size()-2] == 0) && flowerbed[flowerbed.size()-1] == 0) {
            res++;
            flowerbed[flowerbed.size()-1] = 1;
        }            
        // cout << res << endl;
        return res >= n;
    }
};
```

OR 
```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i = 1; i < flowerbed.size()-1; ++i)
        {
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0)
            {
                --n;
                ++i;
            }
                
        }
        return n <=0;
    }
};
```





