class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int, int>> vect;
    int m = matrix.size(); // Number of rows
    int n = matrix[0].size(); // Number of columns

    // Finding the positions of zeroes in the matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                vect.push_back({i, j});
            }
        }
    }

    // Setting rows and columns to zero based on the positions found
    for(auto it = vect.begin(); it != vect.end(); it++) {
        int row = it->first;
        int col = it->second;
        for(int i = 0; i < m; i++) {
            matrix[i][col] = 0;
        }
        for(int j = 0; j < n; j++) {
            matrix[row][j] = 0;
        }
    }
    }
};