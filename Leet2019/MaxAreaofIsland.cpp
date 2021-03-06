#include "stdafx.h"
//Given a non - empty 2D array grid of 0's and 1's, an island is a 
//group of 1's (representing land) connected 4-directionally 
//(horizontal or vertical.) You may assume all four edges of 
//the grid are surrounded by water.
//
//Find the maximum area of an island in the given 2D array. 
//(If there is no island, the maximum area is 0.)
//
//Example 1:
//[[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
//[0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
//[0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
//[0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]
//Given the above grid, return 6. Note the answer is not 11, 
//because the island must be connected 4 - directionally.
//
//Example 2:
//[[0, 0, 0, 0, 0, 0, 0, 0]]
//Given the above grid, return 0.
//Note : The length of each dimension in the given grid does not exceed 50.
namespace Solution2019
{
	namespace MaxAreaofIsland
	{
		int GetSum(vector<vector<int>>& grid, int i, int j, int rowCount, int colCount) {
			if (i < 0 || i >= rowCount || j < 0 || j >= colCount || grid[i][j] == 0) { return 0; }
			grid[i][j] = 0;
			return 1 + GetSum(grid, i - 1, j, rowCount, colCount) + GetSum(grid, i + 1, j, rowCount, colCount) + GetSum(grid, i, j-1, rowCount, colCount) + GetSum(grid, i, j+1, rowCount, colCount);
		}
		
		int maxAreaOfIsland(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return 0; }
			int colCount = grid[0].size();
			if (colCount == 0) { return 0; }
			int sum = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] == 1) {
						sum = max(sum, GetSum(grid, i, j, rowCount, colCount));
					}
				}
			}
			return sum;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

