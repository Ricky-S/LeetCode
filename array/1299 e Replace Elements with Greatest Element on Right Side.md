Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

example 1\
```
Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation: 
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
```

example 2\
```
Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.
```

Idea:\
find the largest element's index, replace all previous elements with this element.

```cpp
// use the original array.
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // vector<int> result(arr.size(), -1);
        for (int i = 0; i<arr.size()-1; i++) {
            int nowIndex = i;
            int maxIndex = max_element(arr.begin()+i+1, arr.end())- (arr.begin()+i+1);
            cout << maxIndex << endl;
            while (maxIndex>=0) {
                arr[i] = arr[i+maxIndex+1];
                cout << "result[i]: " << arr[i] << endl;
                maxIndex--;   
                if (maxIndex != -1) i++;            
            }

            // cout << result[i]<< endl;
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};
```

```cpp
// use new array
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result(arr.size(), -1);
        for (int i = 0; i<arr.size()-1; i++) {
            int nowIndex = i;
            int maxIndex = max_element(arr.begin()+i+1, arr.end())- (arr.begin()+i+1);
            cout << maxIndex << endl;
            while (maxIndex>=0) {
                result[i] = arr[i+maxIndex+1];
                cout << "result[i]: " << result[i] << endl;
                maxIndex--;   
                if (maxIndex != -1) i++;            
            }

            // cout << result[i]<< endl;
        }
        return result;
    }
};
```









