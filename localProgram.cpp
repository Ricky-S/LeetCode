#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 1, slow = 0, dupCount = 0, current;
        int n = nums.size();
        if (n <= 2) return n;
        else {
            while (fast < n) {
                if(nums[slow] != nums[fast]) {
                    slow=fast;
                    fast++; 
                    dupCount = 0;
                } else {
                    dupCount++;
                    if (dupCount >= 2) {
                        for (int ii = fast; ii < n-1; ii++) {
                            nums[ii] = nums[ii+1];
                        }
                        n--;
                    } else {
                        fast++;
                    }
                }
                cout << slow << " " << fast << " " << dupCount << " " << n << endl;
            }
        }
        return n;
    }
};

int main() {
    // int a[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<vector<int>> matrix1
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> matrix2
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };    
    vector<vector<int>> matrix3
    {
        {6,9,7}
    };  
    vector<vector<int>> matrix4
    {
        {2,3,4},
        {5,6,7},
        {8,9,10},
        {11,12,13},
        {14,15,16}                 
    };  
    vector<vector<int>> matrix5
    {
        {1,2,3,4,5,6,7,8,9,10},

        {11,12,13,14,15,16,17,18,19,20}                 
    };  

    string s1 = "leet**cod*e";
    string s2 = "erase*****";
    string s3 = "abcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxz";
    vector<int> nums {1,2,2};
    Solution solution;
    solution.removeDuplicates(nums);
    // with_separator(, ", ");
    return 0;
}