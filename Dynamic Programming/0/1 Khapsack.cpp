// int helper(vector<vector<int>>& dp, vector<int>& wts, vector<int>& val, int idx, int wt){
//     if(idx == val.size() - 1){
//        if(wts[idx] <= wt) return val[idx];
//        return 0;
//     }

//     if(dp[idx][wt] != -1) return dp[idx][wt];

//     int take = INT_MIN;
//     int notTake = helper(dp, wts, val, idx + 1, wt);
//     if(wts[idx] <= wt){
//         take = val[idx] + helper(dp, wts, val, idx + 1, wt - wts[idx]);
//     }

//     dp[idx][wt] = max(take, notTake);
//     return dp[idx][wt];
// }

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> dp(maxWeight + 1, 0);
    dp[0] = 0;
    //     return helper(dp, weight, value, 0, maxWeight);

    for (int i = 0; i < n; ++i)
    { // Since we may only take a weight once, we iterate over the
      // give weights individiually instead of iterting over every
      // possible weigth from 0 to maxWeight
        for (int j = maxWeight; j >= 0; --j)
        { //                                                 We go from the maxWeight to 0 becuase if we were
            //                                                 to go from 0 to the maxWeight, then when calling
            //                                                 out the max function when we look to the index
            //                                                 behind (dp[i - weight[i]]) we will accidentally
            //                                                 retake the same weight again, however this goes
            //                                                 against the rule as we may only take a weight once.
            if (weight[i] <= j)
            {
                dp[j] = max(value[i] + dp[j - weight[i]], dp[j]);
            }
        }
    }

    return dp[maxWeight];
}