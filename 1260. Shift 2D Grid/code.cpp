// Using the last variable to store the last element we recursed on, and a temp variable to save the state of the variable we can swap
//and find the asnwer. 

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(int n = 0; n < k; ++n){
            int last = grid[0][0];
            for(int i = 0; i < size(grid); ++i){
                for(int j = 0; j < size(grid[0]); ++j){
                    int tmp = grid[i][j];
                    grid[i][j] = last;
                    last = tmp;
                }
            }
            grid[0][0] = last;
        }
        
        
        return grid;
    }
};