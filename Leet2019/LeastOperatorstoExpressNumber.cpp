#include "stdafx.h"

//Given a single positive integer x, we will write an expression of the form x
//(op1) x (op2) x (op3) x ... where each operator op1, op2, etc. is either
//addition, subtraction, multiplication, or division (+, -, *, or /).  For
//example, with x = 3, we might write 3 * 3 / 3 + 3 - 3 which is a value of 3.
//When writing such an expression, we adhere to the following conventions:
//The division operator (/) returns rational numbers.
//There are no parentheses placed anywhere.
//We use the usual order of operations: multiplication and division happens
//before addition and subtraction.
//It's not allowed to use the unary negation operator (-).  For example, "x - x"
//is a valid expression as it only uses subtraction, but "-x + x" is not because
//it uses negation.
//We would like to write an expression with the least number of operators such
//that the expression equals the given target.  Return the least number of
//operators used.
// 
//
//Example 1:
//Input: x = 3, target = 19
//Output: 5
//Explanation: 3 * 3 + 3 * 3 + 3 / 3.  The expression contains 5 operations.
//
//Example 2:
//Input: x = 5, target = 501
//Output: 8
//Explanation: 5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5.  The expression contains 8
//operations.
//
//Example 3:
//Input: x = 100, target = 100000000
//Output: 3
//Explanation: 100 * 100 * 100 * 100.  The expression contains 3 operations.
// 
//
//Note:
//2 <= x <= 100
//1 <= target <= 2 * 10^8

namespace Solution2019
{
	namespace LeastOperatorstoExpressNumber
	{
		namespace DP {
			int dp(int x, int t, unordered_map<int, int>& map) {
				if (t == 0) { return 0; }
				if (t < x) {
					return min(2 * t - 1, 2 * (x - t));
				}
				if (map.find(t) != map.end()) { return map[t]; }

				int k = log(t) / log(x);
				long long p = pow(x, k);
				if (t == p) {
					map[t] = k - 1;
					return map[t];
				}
				int result = dp(x, t - p, map) + k;
				long long left = p * x - t;
				if (left < t) {
					result = min(result, dp(x, left, map) + k + 1);
				}
				map[t] = result;
				return map[t];
			}

			int leastOpsExpressTarget(int x, int target) {
				unordered_map<int, int> map;
				return dp(x, target, map);
			}
		}

		namespace BFS {
			int leastOpsExpressTarget(int x, int target) {
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
				unordered_set<int> s;
				q.push({ 0, target });
				while (!q.empty()) {
					const int c = q.top().first;
					const int t = q.top().second;
					q.pop();
					if (t == 0) { return c - 1; }
					if (s.count(t)) { continue; }
					s.insert(t);
					int n = log(t) / log(x);
					int l = t - pow(x, n);
					if (!s.count(l)) {
						q.push({ c + (n == 0 ? 2 : n), l });
					}
					int r = pow(x, n + 1) - t;
					if (!s.count(l)) {
						q.push({ c + n + 1, r });
					}
				}
				return -1;
			}
		}

		namespace SlowButEasyToUnderstand {
			int leastOpsExpressTarget(int x, int target) {
				if (x > target) {
					return min(target * 2 - 1, (x - target) * 2);
				}
				if (x == target) {
					return 0;
				}

				long long sums = x;
				int times = 0;
				while (sums < target) {
					times++;
					sums *= x;
				}

				if (sums == target) { return times; }
				int l = INT_MAX;
				if (sums - target < target) {
					l = leastOpsExpressTarget(x, sums - target) + times;
				}
				int r = leastOpsExpressTarget(x, target - (sums / x)) + times - 1;
				return min(l, r) + 1;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

