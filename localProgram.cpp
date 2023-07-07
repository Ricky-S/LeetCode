#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxLen = 0;
        int kLen = k;
        int i = 0;
        int j = 0;
        int keyLen = 0;
        for (i = 0; i < answerKey.size(); i++) {
            if (answerKey[i] == 'T') {
                keyLen++;
            } else {
                kLen--;
                
                if(kLen == -1) {
                    kLen++;
                    while(answerKey[j] == 'T') {
                        keyLen--;
                        j++;
                    }
                    j++;
                } else {
                    keyLen++;
                }
            }
            maxLen = max(maxLen, keyLen);
            cout << kLen << " " << maxLen << endl;
        }
        keyLen = 0;
        kLen = k;
        j = 0;
        for (i = 0; i < answerKey.size(); i++) {
            if (answerKey[i] == 'F') {
                keyLen++;
            } else {
                kLen--;
                
                if(kLen == -1) {
                    kLen++;
                    while(answerKey[j] == 'F') {
                        keyLen--;
                        j++;
                    }
                } else {
                    keyLen++;
                }
            }
            maxLen = max(maxLen, keyLen);
            cout << kLen << " " << maxLen << endl;
        }
        return maxLen;
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
    string s3 = "FTFFTFTFTTFTTFTTFFTTFFTTTTTFTTTFTFFTTFFFFFTTTTFTTTTTTTTTFTTFFTTFTFFTTTFFFFFTTTFFTTTTFTFTFFTTFTTTTTTF";
    vector<int> nums {1,2,2};
    Solution solution;
    solution.maxConsecutiveAnswers(s3, 32);
    // with_separator(, ", ");
    return 0;
}