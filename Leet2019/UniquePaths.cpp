#include "stdafx.h"
//A robot is located at the top - left corner of a m x n grid
//(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in 
//time.The robot is trying to reach the bottom - right corner 
//of the grid(marked 'Finish' in the diagram below).
//
//How many possible unique paths are there ?
//
//
//Above is a 7 x 3 grid.How many possible unique paths are
//there ?
//
//Note : m and n will be at most 100.
//
//Example 1 :
//Input : m = 3, n = 2
//Output : 3
//Explanation :
//	From the top - left corner, there are a total of 3 ways 
//	to reach the bottom - right corner :
//	1. Right->Right->Down
//	2. Right->Down->Right
//	3. Down->Right->Right
//
//Example 2 :
//Input : m = 7, n = 3
//Output : 28

namespace Solution2019
{
	namespace UniquePaths
	{
		namespace Math {
			int uniquePath(int m, int n) {
				int N = m + n - 2;
				int k = m - 1;

				// here we calculate the total possible path number 
				// Combination(N, k) = n! / (k!(n - k)!)
				// reduce the numerator and denominator and get
				// C = ( (n - k + 1) * (n - k + 2) * ... * n ) / k!
				double result = 1;
				for (int i = 1; i <= k; i++) {
					result = result * (N - k + i) / i;
				}
				return (int)result;
			}
		}
		namespace DP {
			int uniquePath(int m, int n) {
				vector<int>dp(n, 1);
				for (int i = 1; i < m; i++) {
					for (int j = 1; j < n; j++) {
						dp[j] += dp[j - 1];
					}
				}
				return dp[n - 1];
			}
		}


		namespace TooSlow {
			void helper(int row, int col, int rowCount, int colCount, int& result) {
				if (row == rowCount - 1 && col == colCount - 1) { result++; }
				if (row >= rowCount || col >= colCount) { return; }

				helper(row + 1, col, rowCount, colCount, result);
				helper(row, col + 1, rowCount, colCount, result);
			}

			int uniquePaths(int m, int n) {
				int result = 0;
				helper(0, 0, m, n, result);
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

