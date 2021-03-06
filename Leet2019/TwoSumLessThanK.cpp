#include "stdafx.h"
//Given an array A of integers and integer K, return the maximum S
//such that there exists i < j with A[i] + A[j] = S and S < K. 
//If no i, j exist satisfying this equation, return -1.
//
//Example 1:
//Input: A = [34,23,1,24,75,33,54,8], K = 60
//Output: 58
//Explanation: 
//We can use 34 and 24 to sum 58 which is less than 60.
//
//Example 2:
//Input: A = [10,20,30], K = 15
//Output: -1
//Explanation: 
//In this case it's not possible to get a pair sum less that 15.
// 
//Note:
//1 <= A.length <= 100
//1 <= A[i] <= 1000
//1 <= K <= 2000 

namespace Solution2019
{
	namespace TwoSumLessThanK
	{
		int twoSumLessThanK(vector<int>& A, int K) {
			int i = 0;
			int j = A.size() - 1;
			sort(A.begin(), A.end());
			while (A[j] >= K) { j--; }

			int result = INT_MIN;
			while (i < j) {
				if (A[i] + A[j] >= K) {
					j--;
				}
				else  {
					result = max(result, A[i] + A[j]);
					if (A[i + 1] + A[j] >= K) { j--; }
					i++;
				}
			}
			return result == INT_MIN ? -1 : result;
		}



		int getSumLessThan(vector<int> A, int i, int k) {
			int target = k - A[i];
			int start = 0;
			int end = i - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (A[mid] >= target) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			if (end < 0) { return -1; }
			return A[i] + A[end];
		}

		int twoSumLessThanKSlow(vector<int>& A, int K) {
			sort(A.begin(), A.end());
			int i = A.size()-1;
			while (i >= 0) {
				if (A[i] >= K) { i--; }
				else { break; }
			}

			int result = INT_MIN;
			for (i; i >= 0; i--) {
				int sum = getSumLessThan(A, i, K);
				result = max(result, sum);
			}
			return result;
		}

		void Main() {
			vector<int> A = { 34, 23, 1, 24, 75, 33, 54, 8 };
			print(twoSumLessThanK(A, 60));
			A = { 10,20,30 };
			print(twoSumLessThanK(A, 15));
		}
	}
}

