#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int count = 0;
        string result = "";
        vector<int> index(s.size(), -1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                count++;
                index[i] = i;
            } else {
                // result.push_back(s[i]);
            }
        }
        int i = 0, jStar = 0, sIndex = 0;
        for (sIndex = 0; sIndex < s.size(); sIndex++) {
            if (s[sIndex] == '*') {
                // jStar++;
                result.pop_back();
            } else {
                result.push_back(s[sIndex]);
            }
        }
        for (int i = 0, j = 0; i < s.size(); i++) 
            cout << "indexi" << index[i] << endl;
        cout << count << endl;
        cout << result << endl;

        return s;
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
    Solution solution;
    solution.removeStars(s3);
    // with_separator(, ", ");
}