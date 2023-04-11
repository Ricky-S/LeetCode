#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();// how many rows
        int n = matrix[0].size(); // how many columns

        cout << m << "m  n" << n << endl;

        vector<int> output(m * n, 0);

        cout << output.size() << endl;


        int istart = 0; 
        int jstart = 0;
        int iend = n - 1; 
        int jend = m - 1;
        int i=0, j=0;
        int index = 0;
        int flag = 100;
        int cycles = m < n ? m/2 : n/2;
        cout<< cycles << endl;
        cout << m << " " << n << endl;

        if(m == 1) {
            index = 0;
            for (int ii = istart; ii <= iend; ii++) {
                // cout << "i" << i << "aa" << matrix[j][i]<<endl;
                output[index++] = matrix[0][ii];
                // cout << "i" << i << "aa" << matrix[j][i]<<endl;
            }            
        } else if (n == 1) {
            index = 0;
            for (int ii = jstart; ii <= jend; ii++) {
                // cout << "i" << i << "aa" << matrix[j][i]<<endl;
                output[index++] = matrix[ii][0];
                // cout << "i" << i << "aa" << matrix[j][i]<<endl;
            }    
        }else {
            index = 0;
            while(cycles--) {
                cout << istart << " " << iend <<endl;
                cout << jstart << " " << jend <<endl;
                i = istart;
                j = jstart;
                for (i = istart; i < iend; i++) {
                    // cout << "i" << i << "aa" << matrix[j][i]<<endl;
                    if (index < m*n) output[index] = matrix[j][i];
                    index++;
                    cout << "i" << i << "aa" << matrix[j][i]<<endl;
                }
                for (j = jstart; j < jend; j++) {
                    if (index < m*n) output[index] = matrix[j][i];
                    index++;
                    cout << "j" << j << "aa" << matrix[j][i]<<endl;
                }
                for (; i > istart; i--) {
                    if (index < m*n) output[index] = matrix[j][i];
                    index++;
                    cout << "i" << i << "aa" << matrix[j][i]<<endl;
                }        
                for (; j > jstart; j--) {
                    if (index < m*n) output[index] = matrix[j][i];
                    index++;
                    cout << "j" << j << "aa" << matrix[j][i]<<endl;
                }
                istart++;jstart++;
                iend--; jend--;
                cout << "istart" << istart << "iend" << iend << "jstart" << jstart << "jend" << jend << endl;
                // if (is)
            }

            // may left one row or one column
            if (jstart == jend) {
                for (i = istart; i <= iend; i++) {
                    // cout << "i" << i << "aa" << matrix[j][i]<<endl;
                    cout << "index" << index << endl;
                    if (index < m*n) output[index] = matrix[jstart][i];
                    index++;
                    cout << "i" << i << "aa" << matrix[jstart][i]<<endl;
                }
            }
            if (istart == iend) {
                for (i = jstart; i <= jend; i++) {
                    // cout << "i" << i << "aa" << matrix[j][i]<<endl;
                    cout << "index" << index << endl;
                    if (index < m*n) output[index] = matrix[i][istart];
                    index++;
                    cout << "i" << i << "aa" << matrix[i][istart]<<endl;
                }
            }            

            
            

            if (m == n && m % 2 == 1) {
                int index = m/2;
                output[m * n - 1] = matrix[index][index];
            }

        }
        for (int ii = 0; ii < m*n; ii++) {
            cout << output[ii] << endl;
        }
        return output;        
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
    // cout << matrix1[1][1] << endl;
    // vector<int> matrix1(3, 0);
    Solution solution;
    solution.spiralOrder(matrix2);
    // with_separator(, ", ");
}