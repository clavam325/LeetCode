class Solution {
public:
    
    void printMat(vector<vector<int>>& matrix) {

        for(auto vec : matrix) {
            for(auto i : vec)
                cout << i << " " ;
            cout << endl;
        }
    }

    int calcMin(vector<vector<int>>& matrix, int k) {
        
        int minm = matrix[0][0];
        int i = 0, j = 0;
        int n = matrix.size();
        matrix[0][0] = INT_MAX;
        
        while( (i+1 < n) || (j+1 < n) ) {
            
            if(i+1 < n) {

                if(j+1 < n) {

                    if( matrix[i+1][j] < matrix[i][j+1] ) {
                        swap(matrix[i][j], matrix[i+1][j]);
                        i++;
                    } else {
                        swap(matrix[i][j], matrix[i][j+1]);
                        j++;
                    }
                } else {

                    if( matrix[i+1][j] < matrix[i][j] ) {
                        swap(matrix[i][j], matrix[i+1][j]);
                        i++;
                    } else {
                        break;
                    }

                }
            } else {

                if( matrix[i][j+1] < matrix[i][j] ) {
                    swap(matrix[i][j], matrix[i][j+1]);
                    j++;
                } else {
                    break;
                }
            }
        }

        printMat(matrix);

        cout << " Minm is "<< minm << endl;

        return minm;
            
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        if(matrix.size() == 0)
            return -1;
        
        int ans = 0;
        for(int i = 0 ; i < k ; i++) {
            ans = calcMin(matrix, k);
        }
        
        return ans;
    }
};