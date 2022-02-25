#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        for(int i = 1; i < colors.length(); ++i){
            if(colors[i - 1] == colors[i]){
                time += min(neededTime[i-1], neededTime[i]);
                neededTime[i-1] = neededTime[i] = max(neededTime[i-1], neededTime[i]);
            }         
        }
        return time;
    }
};