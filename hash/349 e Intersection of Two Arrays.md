Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

example 1\
```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

example 2\
```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```


idea:\
unorderd set

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // to avoid duplicate number
        unordered_set<int> firstVector{nums1.begin(), nums1.end()};
        cout << firstVector.size() << endl;
        for (int i : nums2) {
            if (firstVector.find(i) != firstVector.end()) {
                result_set.insert(i);
            }
        }
    
    return vector<int>(result_set.begin(), result_set.end());

    }
};

int main() {
    vector<int> nums1{1,2,2,1,3}, nums2{2,2};
    Solution solution;
    solution.intersection(nums1, nums2);
}
```

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // to avoid duplicate number
        unordered_set<int> firstVector{nums1.begin(), nums1.end()};
        cout << firstVector.size() << endl;
        for (int i : nums2) {
            if (firstVector.find(i) != firstVector.end()) {
                result_set.insert(i);
            }
        }
    
    return vector<int>(result_set.begin(), result_set.end());

    }
};

int main() {
    vector<int> nums1{1,2,2,1,3}, nums2{2,2};
    Solution solution;
    solution.intersection(nums1, nums2);
}
```

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int hash[1000] = {0};
        unordered_set<int> result;
        for (int i = 0; i < nums1.size(); i++) { //or for (int num : nums1)
            hash[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (hash[nums2[i]] == 1) {
                result.insert(nums2[i]);
            }
        }        

        return vector<int>(result.begin(), result.end());
    }
};

int main() {
   
    vector<int> nums1{1,2,2,1,3}, nums2{2,2};
    Solution solution;
    solution.intersection(nums1, nums2);
}
```


















