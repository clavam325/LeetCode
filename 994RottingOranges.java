 class Solution {

        int rot(int[][] grid, int r, int c, int days) {

            if(r < 0 || c < 0 || r >= grid.length || c >= grid[r].length || grid[r][c] != 1)
                return 0;

            grid[r][c] = days + 3;
            return 1;
        }

        public int orangesRotting(int[][] grid) {

            int fresh = 0, days = 0;

            for(int i = 0 ; i < grid.length ; i++) {
                for(int j = 0 ; j < grid[i].length ; j++) {
                    if(grid[i][j] == 1)
                        fresh++;
                }
            }

            for(int oldFresh = fresh ; fresh > 0 ; ++days, oldFresh = fresh ) {
                //System.out.println("Before " + oldFresh + " " + fresh + " days" + days);
                for(int i = 0 ; i < grid.length ; i++) {
                    for(int j = 0 ; j < grid[i].length ; j++) {
                        //System.out.println("i  " + i + " " + j + " grid" + grid[i][j]);
                        if(grid[i][j] == days + 2)
                            fresh -= rot(grid,i+1,j,days) + rot(grid,i,j+1,days) + rot(grid,i-1,j,days) + rot(grid,i,j-1,days);

                        //System.out.println("After " + oldFresh + " " + fresh + " days" + days);

                    }
                }
                if(oldFresh == fresh)
                    return -1;
            }

            return days;
        }
    }