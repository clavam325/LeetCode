//https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void flip(vector<vector<int>>& matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int temp;

        for(int c1 = 0 , c2 = c-1 ; c1 < c2 ; c1++, c2--)
        {
            for(int r1 = 0 ; r1 < r ; r1++)
            {
                temp = matrix[r1][c1];
                matrix[r1][c1] = matrix[r1][c2];
                matrix[r1][c2] = temp;
            }
        }
    }

    void transpose(vector<vector<int>>& matrix)
    {
        int row = matrix.size();
        int col = matrix.size();
        int temp;

        for(int r1 = 0 ; r1 < row-1 ; r1++)
        {
            int r2, c2;

            c2 = col-1-r1;
            r2 = row-1;

            for(int c1 = 0 ; c1 <= col-2-r1 ; c1++, r2--)
            {
                temp = matrix[r1][c1];
                matrix[r1][c1] = matrix[r2][c2];
                matrix[r2][c2] = temp;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {

        if(matrix.size()  == 0)
            return;

        int row = matrix.size();
        int col = matrix.size();

        if(row != col)
            return;

        flip(matrix);

        transpose(matrix);
    }
};
