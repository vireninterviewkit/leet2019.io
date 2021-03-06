#include "stdafx.h"

//Given a matrix of M x N elements (M rows, N columns), return all elements of
//the matrix in diagonal order as shown in the below image.
// 
//
//Example:
//Input:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//Output:  [1,2,4,7,5,3,6,8,9]
//Explanation:
// 
//
//Note:
//The total number of elements of the given matrix will not exceed 10,000.

namespace Solution2019
{
	namespace DiagonalTraverse
	{
		namespace DirectPipe {
			vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
				int rowCount = matrix.size();
				if (rowCount == 0) { return {}; }
				int colCount = matrix[0].size();
				if (colCount == 0) { return {}; }

				vector<int> result(rowCount * colCount);
				int r = 0;
				int c = 0;
				for (int i = 0; i < result.size(); i++) {
					result[i] = matrix[r][c];
					if ((r + c) % 2 == 0) {
						// cannot change the if else sequence, otherwise
						// will have out of bound when both boundary is hit
						if (c == colCount - 1) { r++; } 
						else if (r == 0) { c++; }
						else { r--; c++; }
					}
					else {
						// cannot change the if else sequence, otherwise
						// will have out of bound when both boundary is hit
						if (r == rowCount - 1) { c++; }
						else if (c == 0) { r++; }
						else { r++; c--; }
					}
				}
				return result;
			}
		}

		namespace UseHashMapAndReverse {
			vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
				int rowCount = matrix.size();
				if (rowCount == 0) { return {}; }
				int colCount = matrix[0].size();
				if (colCount == 0) { return {}; }

				map<int, vector<int>> M;
				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						M[i + j].push_back(matrix[i][j]);
					}
				}

				vector<int> result;
				bool r = true;
				for (auto& p : M) {
					if (r) { reverse(p.second.begin(), p.second.end()); }
					for (int v : p.second) { result.push_back(v); }
					r = !r;
				}
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

