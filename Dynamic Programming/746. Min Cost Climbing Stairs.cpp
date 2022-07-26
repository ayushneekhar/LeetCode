#include <bits/stdc++.h>
using namespace std;

// Trick: this is the fibonacci pattern of Dynamic Programming porblem

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int one = 0;     // Represents the cost to get to the 1st stair
        int two = 0;     // Represents the cost to get to the 2nd stair
        int minCost = 0; // Represents the minimum cost to get to ith chair

        for (int i = 2; i <= cost.size(); ++i)
        {
            // The minimum cost to get to the ith stair would be equal to the minimum of wither:
            // 1. From min cost to get to (i - 1)st stair + the cost to move from the (i - 1)st stair itself assuming
            //    we take only one step for the (i - 1) stair to ith stair
            // 1. From min cost to get to (i - 2)nd stair + the cost to move from the (i - 2)st stair itself assuming
            //    we take two steps from (i - 2) stair to ith stair
            // Once the minimum csot is calculated the two i - 1 is updated to i and i - 2 updated to previously i - 1
            minCost = min(cost[i - 1] + two, cost[i - 2] + one);
            one = two;
            two = minCost;
        }

        return minCost;
    }
};