# 2660. Determine the Winner of a Bowling Game

You are given two 0-indexed integer arrays player1 and player2, that represent the number of pins that player 1 and player 2 hit in a bowling game, respectively.

The bowling game consists of n turns, and the number of pins in each turn is exactly 10.

Assume a player hit xi pins in the ith turn. The value of the ith turn for the player is:

2xi if the player hit 10 pins in any of the previous two turns.
Otherwise, It is xi.
The score of the player is the sum of the values of their n turns.

Return

1 if the score of player 1 is more than the score of player 2,\
2 if the score of player 2 is more than the score of player 1, and\
0 in case of a draw.

ex1
```cpp
Input: player1 = [4,10,7,9], player2 = [6,5,2,3]
Output: 1
Explanation: The score of player1 is 4 + 10 + 2*7 + 2*9 = 46.
The score of player2 is 6 + 5 + 2 + 3 = 16.
Score of player1 is more than the score of player2, so, player1 is the winner, and the answer is 1.
```

ex2
```cpp
Input: player1 = [3,5,7,6], player2 = [8,10,10,2]
Output: 2
Explanation: The score of player1 is 3 + 5 + 7 + 6 = 21.
The score of player2 is 8 + 10 + 2*10 + 2*2 = 42.
Score of player2 is more than the score of player1, so, player2 is the winner, and the answer is 2.
```

ex3
```cpp
Input: player1 = [2,3], player2 = [4,1]
Output: 0
Explanation: The score of player1 is 2 + 3 = 5
The score of player2 is 4 + 1 = 5
The score of player1 equals to the score of player2, so, there is a draw, and the answer is 0.
```

Constraints\
```cpp
n == player1.length == player2.length
1 <= n <= 1000
0 <= player1[i], player2[i] <= 10
```

idea:

if n == 1, just compare the only element.

if n is equal or greater than 2, we need to consider the double score.




```cpp
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        // if only one element.
        if (player1.size() == 1) {
            if (player1[0] > player2[0]) return 1;
            else if (player1[0] < player2[0]) return 2;
            else return 0;
        }else if (player1.size() >= 2) { // two or more elements.
            int sum1 = player1[0];
            int sum2 = player2[0];
            // below is to calculate if two elements.
            if (player1[0] == 10) {
                sum1 = sum1 + 2 * player1[1];
                
            } else sum1 = sum1 + player1[1];

            if (player2[0] == 10) {
                sum2 = sum2 + 2 * player2[1];
            } else sum2 = sum2 + player2[1]; 
            //below is to calculate more than 2 elements.
            for (int i = 2; i<player1.size(); i++) {
                if ((player1[i-2] == 10) || (player1[i-1] == 10) ) {
                    sum1 = sum1 + 2 * player1[i];
                    
                } else sum1 = sum1 + player1[i];
                // cout << "sum1" << sum1<< endl;
                if ((player2[i-2] == 10) || (player2[i-1] == 10) ) {
                    sum2 = sum2 + 2 * player2[i];
                } else sum2 = sum2 + player2[i]; 
                // cout << "sum2" << sum2<< endl;          
            }

            if (sum1 > sum2) return 1;
            else if (sum1 < sum2) return 2;
            else return 0;
        }

        return -2;
    }
};
```











