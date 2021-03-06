#include "stdafx.h"

//There are N piles of stones arranged in a row.  The i-th pile has stones[i]
//stones.
//A move consists of merging exactly K consecutive piles into one pile, and the
//cost of this move is equal to the total number of stones in these K piles.
//Find the minimum cost to merge all piles of stones into one pile.  If it is
//impossible, return -1.
// 
//
//Example 1:
//Input: stones = [3,2,4,1], K = 2
//Output: 20
//Explanation: 
//We start with [3, 2, 4, 1].
//We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
//We merge [4, 1] for a cost of 5, and we are left with [5, 5].
//We merge [5, 5] for a cost of 10, and we are left with [10].
//The total cost was 20, and this is the minimum possible.
//
//Example 2:
//Input: stones = [3,2,4,1], K = 3
//Output: -1
//Explanation: After any merge operation, there are 2 piles left, and we can't
//merge anymore.  So the task is impossible.
//
//Example 3:
//Input: stones = [3,5,1,2,6], K = 3
//Output: 25
//Explanation: 
//We start with [3, 5, 1, 2, 6].
//We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
//We merge [3, 8, 6] for a cost of 17, and we are left with [17].
//The total cost was 25, and this is the minimum possible.
// 
//
//Note:
//1 <= stones.length <= 30
//2 <= K <= 30
//1 <= stones[i] <= 100 

namespace Solution2019
{
	namespace MinimumCosttoMergeStones
	{
		const int kINF = 1e9;

		int dp(int i, int j, vector<int>& stones, vector<int>& sums, vector<vector<int>>& cache, int K) {
			const int l = j - i + 1;
			if (l < K) { return 0; }
			if (cache[i][j] != kINF) { return cache[i][j]; }

			int result = kINF;
			for (int m = i; m < j; m += K - 1) {
				result = min(result,
					dp(i, m, stones, sums, cache, K) + dp(m + 1, j, stones, sums, cache, K)
				);
			}
			if ((l - 1) % (K - 1) == 0) { result += sums[j + 1] - sums[i]; }
			cache[i][j] = result;
			return result;
		}

		int mergeStones(vector<int>& stones, int K) {
			int len = stones.size();
			if ((len - 1) % (K - 1) != 0) { return -1; }
			vector<vector<int>> cache(len, vector<int>(len, kINF));
			vector<int> sum(len + 1);
			for (int i = 0; i < len; i++) {
				sum[i + 1] = sum[i] + stones[i];
			}
			return dp(0, len - 1, stones, sum, cache, K);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

