#include "stdafx.h"
//A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers 
//from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//
//Given an grid of integers, how many 3 x 3 "magic square" subgrids 
//are there?  (Each subgrid is contiguous).
//
//Example 1:
//Input: [[4,3,8,4],
//        [9,5,1,9],
//        [2,7,6,2]]
//Output: 1
//Explanation: 
//The following subgrid is a 3 x 3 magic square:
//438
//951
//276
//
//while this one is not:
//384
//519
//762
//
//In total, there is only one magic square inside the given grid.
//Note:
//
//1 <= grid.length <= 10
//1 <= grid[0].length <= 10
//0 <= grid[i][j] <= 15
namespace Solution2019
{
	namespace MagicSquaresInGrid
	{
		bool check(const vector<vector<int>>& G, int row, int col) {
			int map[16] = { 0 };
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					map[G[row+i][col+j]]++;
				}
			}
			for (int i = 1; i <= 9; i++) { if (map[i] == 0) { return false; } }

			int target = G[row][col] + G[row][col+1] + G[row][col+2];
			for (int i = 1; i < 3; i++) {
				if (G[row + i][col] + G[row + i][col + 1] + G[row + i][col + 2] != target) {
					return false; 
				}
			}
			for (int i = 0; i < 3; i++) {
				if (G[row][col+i] + G[row + 1][col+i] + G[row + 2][col+i] != target) { 
					return false; 
				}
			}
			if (G[row][col] + G[row + 1][col + 1] + G[row + 2][col + 2] != target) { 
				return false; 
			}
			if (G[row][col+2] + G[row + 1][col + 1] + G[row + 2][col] != target) {
				return false; 
			}
			return true;
		}

		int numMagicSquaresInside(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount < 3) { return 0; }
			int colCount = grid[0].size();
			if (colCount < 3) { return 0; }

			int result = 0;
			for (int i = 0; i < rowCount-2; i++) {
				for (int j = 0; j < colCount-2; j++) {
					if (check(grid, i, j)) { result++; }
				}
			}
			return result;
		}

		void Main() {
			vector<vector<int>> test = { {4,3,8,4},{9,5,1,9},{2,7,6,2} };
			print(numMagicSquaresInside(test));
		}
	}
}

