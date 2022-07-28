#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1); // An array to store the minimum amount of tries it takes to reach the value i using the given coins, i being the index;
        // We take defualt value as 1 as, given any denomination of coin, the max tries it might take to reach is can be i itself, so amount + 1 will be greater than i;
        dp[0] = 0; // To reach amount 0 it takes 0 coins, obviously

        for (int i = 1; i < amount + 1; ++i)
        { // starting from1 calculating the minimum number of ways it takes to reach the amount i
            for (auto it : coins)
            {
                if (i - it >= 0)
                {                                       // if non-negative that means we might have a possible solution, so we try with each coin if we can reach the solution and only take the minimum tries
                    dp[i] = min(dp[i], 1 + dp[i - it]); // to reach value 7 using coins {1, 3, 4, 5} we have 1 + dp[4] taking coin as 3, or 1 + dp[3] taking coin as 4, we add one, since we're using a coin.
                }
            }
        }

        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }
};