// Same as Spiral Matrix II just push instead of value

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        vector<int> res;
        
        while(r1 <= r2 && c1 <= c2){
            // left to right
            for(int i = c1; i <= c2; ++i)
                res.push_back(matrix[r1][i]);
            
            
            // top to bottom
            for(int i = r1 + 1; i <= r2; ++i)
                res.push_back(matrix[i][c2]);
            
            
            if(r2 > r1 && c2 > c1){
                // right to left
                for(int i = c2 - 1; i > c1; i--)
                    res.push_back(matrix[r2][i]);

                // bottom to top
                for(int i = r2; i > r1; --i)
                    res.push_back(matrix[i][c1]);
            }
            
            r1++;
            c1++;
            r2--;
            c2--;
        }
        
        return res;
    }
};