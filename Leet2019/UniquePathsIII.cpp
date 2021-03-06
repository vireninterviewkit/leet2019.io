#include "stdafx.h"

//On a 2-dimensional grid, there are 4 types of squares:
//1 represents the starting square.  There is exactly one starting square.
//2 represents the ending square.  There is exactly one ending square.
//0 represents empty squares we can walk over.
//-1 represents obstacles that we cannot walk over.
//Return the number of 4-directional walks from the starting square to the ending
//square, that walk over every non-obstacle square exactly once.
// 
//
//Example 1:
//Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
//Output: 2
//Explanation: We have the following two paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
//2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
//
//Example 2:
//Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
//Output: 4
//Explanation: We have the following four paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
//2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
//3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
//4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
//
//Example 3:
//Input: [[0,1],[2,0]]
//Output: 0
//Explanation: 
//There is no path that walks over every empty square exactly once.
//
//Note that the starting and ending square can be anywhere in the grid.
// 
//
//Note:
//1 <= grid.length * grid[0].length <= 20 

namespace Solution2019
{
	namespace UniquePathsIII
	{
		void dfs(vector<vector<int>>& grid, int rowCount, int colCount, int x, int y, int ex, int ey, int& empty, int& result) {
			if (x < 0 || x >= rowCount || y < 0 || y >= colCount || grid[x][y] < 0) { return; }
			if (x == ex && y == ey) {
				if (empty < 0) { result++; }
				return;
			}
			grid[x][y] = -2;
			empty--;
			dfs(grid, rowCount, colCount, x - 1, y, ex, ey, empty, result);
			dfs(grid, rowCount, colCount, x + 1, y, ex, ey, empty, result);
			dfs(grid, rowCount, colCount, x, y - 1, ex, ey, empty, result);
			dfs(grid, rowCount, colCount, x, y + 1, ex, ey, empty, result);
			grid[x][y] = 0;
			empty++;
		}



		int uniquePathsIII(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			int colCount = grid[0].size();
			int v;
			int sx=0, sy=0, ex=0, ey=0;
			int empty = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					v = grid[i][j];
					if (v == 0) { empty++; }
					else if (v == 1) { sx = i; sy = j; }
					else if (v == 2) { ex = i; ey = j; }
				}
			}

			int result = 0;
			dfs(grid, rowCount, colCount, sx, sy, ex, ey, empty, result);
			return result;
		}

		void Main() {
			vector<vector<int>> test = { {1,0,0,0},{0,0,0,0},{0,0,2,-1} };
			print(uniquePathsIII(test));
		}
	}
}

