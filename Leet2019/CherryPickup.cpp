#include "stdafx.h"
//In a N x N grid representing a field of cherries, each cell is one of three possible integers.
//
//0 means the cell is empty, so you can pass through;
//1 means the cell contains a cherry, that you can pick up and pass through;
//-1 means the cell contains a thorn that blocks your way.
// 
//Your task is to collect maximum number of cherries possible 
//by following the rules below:
//
//Starting at the position (0, 0) and reaching (N-1, N-1) by moving 
//right or down through valid path cells (cells with value 0 or 1);
//After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
//When passing through a path cell containing a cherry, you pick it up 
//and the cell becomes an empty cell (0);
//If there is no valid path between (0, 0) and (N-1, N-1), then no 
//cherries can be collected.
//
//Example 1:
//Input: grid =
//[[0, 1, -1],
// [1, 0, -1],
// [1, 1,  1]]
//Output: 5
//Explanation: 
//The player started at (0, 0) and went down, down, right right to reach (2, 2).
//4 cherries were picked up during this single trip, and the matrix 
//becomes [[0,1,-1],[0,0,-1],[0,0,0]].
//Then, the player went left, up, up, left to return home, picking up one more cherry.
//The total number of cherries picked up is 5, and this is the maximum possible.
// 
//
//Note:
//grid is an N by N 2D array, with 1 <= N <= 50.
//Each grid[i][j] is an integer in the set {-1, 0, 1}.
//It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.
 

namespace Solution2019
{
	namespace CherryPickup
	{
		int dp(int r1, int c1, int r2, vector<vector<int>>& grid, vector<vector<vector<int>>>& M) {
			int c2 = r1 + c1 - r2;
			if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0) { return -1; }
			if (grid[r1][c1] < 0 || grid[r2][c2] < 0) { return -1; }
			if (r1 == 0 && c1 == 0) { return grid[r1][c1]; }
			if (M[r1][c1][r2] != INT_MIN) { return M[r1][c1][r2]; }
			int result = max(max(dp(r1 - 1, c1, r2 - 1, grid, M), dp(r1, c1 - 1, r2, grid, M)),
				             max(dp(r1, c1 - 1, r2 - 1, grid, M), dp(r1 - 1, c1, r2, grid, M)));
			if (result < 0) {
				M[r1][c1][r2] = -1;
				return -1;
			}
			result += grid[r1][c1];
			if (r1 != r2) { result += grid[r2][c2]; }
			M[r1][c1][r2] = result;
			return result;
		}

		int cherryPickup(vector<vector<int>>& grid) {
			int n = grid.size();
			vector<vector<vector<int>>> M(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
			return max(0, dp(n - 1, n - 1, n - 1, grid, M));
		}


		void Main() {
			vector<vector<int>> test = { {0,1,-1},{1,0,-1},{1,1,1} };
			print(cherryPickup(test));
		}
	}
}

