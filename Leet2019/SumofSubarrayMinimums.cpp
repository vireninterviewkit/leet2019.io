#include "stdafx.h"
//Given an array of integers A, find the sum of min(B), 
//where B ranges over every (contiguous) subarray of A.
//
//Since the answer may be large, return the answer modulo 10^9 + 7.
//
//Example:
//Input: [3,1,2,4]
//Output: 17
//Explanation: Subarrays are 
//[3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
//Minimums are 
//3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  
//Sum is 17.
// 
//Note:
//1 <= A.length <= 30000
//1 <= A[i] <= 30000

namespace Solution2019
{
	namespace SumofSubarrayMinimums
	{
		int sumSubarrayMins(vector<int>& A) {
			stack<pair<int, int>> ple;
			stack<pair<int, int>> nle;

			int len = A.size();
			// left is for the distance to previous less element
			// right is for the distance to next less element
			vector<int> left(len);
			vector<int> right(len);
			for (int i = 0; i < len; i++) {
				left[i] = i + 1;
				right[i] = len - i;
			}

			for (int i = 0; i < len; i++) {
				while (!ple.empty() && ple.top().first > A[i]) {
					ple.pop();
				}
				left[i] = ple.empty() ? i + 1 : i - ple.top().second;
				ple.push({ A[i], i });


				while (!nle.empty() && nle.top().first > A[i]) {
					pair<int, int> x = nle.top();
					nle.pop();
					right[x.second] = i - x.second;
				}
				nle.push({ A[i], i });
			}

			int result = 0;
			int mod = 1e9 + 7;
			for (int i = 0; i < len; i++) {
				result = (result + A[i] * left[i] * right[i]) % mod;
				// result = (result + (A[i] * left[i] * right[i]) % mod) % mod; 
				// (a + b)%n = (a%n + b%n)%n
			}
			return result;

			/* Below is also fine
			long long result = 0;
			long long mod = 1e9+7;
			for (int i = 0; i<len; i++) {
				result += A[i] * left[i] * right[i];
			}
			return (int)(result%mod);   
			*/
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

